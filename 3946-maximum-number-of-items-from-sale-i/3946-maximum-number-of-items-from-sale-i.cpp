class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int solve(int idx, vector<vector<int>>& items, int rem_budget, int mini, vector<int>& val) {
        // Saare items consider ho gaye.
        // Bacha hua budget sabse saste item (mini) par spend karke
        // jitne additional items kharid sakte hain, woh answer mein add honge.
        if (idx == n) {
            return rem_budget / mini;
        }

        // Same index aur same remaining budget ka result pehle calculate hua hai,
        // toh recursion dobara chalane ke bajaye cached answer return karo.
        if (dp[idx][rem_budget] != -1) return dp[idx][rem_budget];

        // Option 1: Current item nahi kharidna.
        // Isse budget spend nahi hoga aur next item consider hoga.
        int skip = solve(idx + 1, items, rem_budget, mini, val);

        // Option 2: Current item kharidna.
        // Initially 0 rakha hai, kyunki budget kam hua toh buy possible nahi hai.
        int buy = 0;

        if (rem_budget >= items[idx][1]) {
            // Current item ki price budget se subtract karo.
            // val[idx] current item kharidne par milne wale total items ko represent karta hai.
            // Uske baad remaining items ke liye maximum answer calculate karo.
            buy = val[idx] + solve(idx + 1, items, rem_budget - items[idx][1], mini, val);
        }

        // Buy aur skip mein se jo maximum items deta hai, use memoize karke return karo.
        return dp[idx][rem_budget] = max(buy, skip);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n = items.size();

        // Har item ke liye initial value 1 hai:
        // item kharidne par woh item khud bhi count hota hai.
        vector<int> val(n, 1);

        int min_price = INT_MAX;

        // Har item ki value precompute karte hain.
        // Agar kisi doosre item ka price current item ke price ka multiple hai,
        // toh current item kharidne par us doosre item ko bhi milne wali value count hoti hai.
        for (int i = 0; i < n; i++) {
            min_price = min(min_price, items[i][1]);

            for (int j = 0; j < n; j++) {
                // i != j: same item ko dobara count nahi karna.
                // Divisibility condition satisfy hui toh current item's value increase karo.
                if (i != j && items[j][0] % items[i][0] == 0) {
                    val[i]++;
                }
            }
        }

        // dp[idx][rem_budget]:
        // idx se aage ke items consider karte hue, rem_budget ke saath
        // maximum kitne items mil sakte hain.
        // -1 ka matlab state abhi calculate nahi hui.
        dp.assign(n, vector<int>(budget + 1, -1));

        // Index 0 se saare items consider karo, full budget available hai,
        // aur base case ke liye cheapest item ki price pass karo.
        return solve(0, items, budget, min_price, val);
    }
};