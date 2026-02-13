class Solution {
public:
    int climbStairs(int n) {

        // dp[i] store karega number of ways to reach stair i
        vector<int> dp(n+1, -1);

        // Base case:
        // stair 0 tak pahunchne ka 1 way hai (do nothing)
        dp[0] = 1;

        // stair 1 tak pahunchne ka 1 way hai (single step)
        dp[1] = 1;

        // Build solution from 2 to n
        for(int i = 2; i <= n; i++){

            // Ways to reach stair i:
            // from (i-1) using 1 step
            // from (i-2) using 2 steps
            dp[i] = dp[i-1] + dp[i-2];
        }

        // Return total ways to reach nth stair
        return dp[n];
    }
};
