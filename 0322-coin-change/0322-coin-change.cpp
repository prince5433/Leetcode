class Solution {
public:
    vector<int> dp;

    int ftd(int x, vector<int>& coins) {

        // BASE CASE:
        // Amount 0 banane ke liye koi coin nahi chahiye.
        if(x == 0)
            return 0;

        // Agar current amount ka answer already calculate hai,
        // toh repeated recursion avoid karne ke liye wahi return karo.
        if(dp[x] != -2)
            return dp[x];

        // Initially assume karo ki answer possible nahi hai.
        int result = INT_MAX;

        // Har available coin ko try karo.
        for(int i = 0; i < coins.size(); i++) {

            // Agar coin current amount se bada hai,
            // toh use subtract nahi kar sakte.
            if(x - coins[i] < 0)
                continue;

            // Coin use karne ke baad remaining amount solve karo.
            // Minimum coins wala result choose karo.
            result = min(result, ftd(x - coins[i], coins));
        }

        // Agar koi bhi combination amount nahi bana paya,
        // toh current amount bhi impossible hai.
        if(result == INT_MAX)
            return dp[x] = INT_MAX;

        // Ek coin use kiya hai, isliye remaining answer mein 1 add karo.
        return dp[x] = 1 + result;
    }

    int coinChange(vector<int>& coins, int amount) {

        // Har test case ke liye fresh DP array initialize karo.
        dp.clear();
        dp.resize(amount + 1, -2);

        int ans = ftd(amount, coins);

        // INT_MAX ka matlab amount banana impossible hai.
        if(ans == INT_MAX)
            return -1;

        return ans;
    }
};

// TC: O(Amount * Number of coins)
// SC: O(Amount) — DP array + recursion stack.