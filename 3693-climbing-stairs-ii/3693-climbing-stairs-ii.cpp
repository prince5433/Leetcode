
class Solution {
public:
    vector<int> dp;

    int solve(int i, int n, vector<int>& cost) {

        // Base case:
        // Agar i == n ho gaya, toh hum destination par pahunch gaye.
        // Ab koi additional cost nahi lagegi.
        if(i == n) return 0;

        // Agar current state pehle calculate ho chuki hai,
        // toh stored answer return kar do.
        if(dp[i] != -1) return dp[i];

        // Minimum cost initially infinity rakhenge.
        int ans = INT_MAX;

        // Hum maximum 3 steps jump kar sakte hain.
        for(int jump = 1; jump <= 3; jump++) {

            int next = i + jump;

            // Check karo ki jump destination se aage toh nahi ja raha.
            if(next <= n) {

                // Total cost =
                // Landing stair ki cost
                // + jump ki additional cost
                // + next position se destination tak minimum cost.
                int currentCost = cost[next - 1]
                                + jump * jump
                                + solve(next, n, cost);

                // Sabhi possible jumps mein minimum choose karo.
                ans = min(ans, currentCost);
            }
        }

        // Current state ka answer store kar do.
        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {

        // Har index ke liye initially answer unknown hai.
        dp.assign(n + 1, -1);

        // Starting position index 0 hai.
        return solve(0, n, costs);
    }
};

/*
TIME COMPLEXITY:

1. Total states = n + 1 (indices 0 to n).
2. Har state maximum 3 jumps check karti hai.
3. Har state sirf ek baar calculate hoti hai due to memoization.
4. Har state ka work = O(3) = O(1).

Total TC = O(n * 3) = O(n).

SPACE COMPLEXITY:

1. DP array = O(n).
2. Recursion stack = O(n) in the worst case.

Total SC = O(n) + O(n) = O(n).
*/
