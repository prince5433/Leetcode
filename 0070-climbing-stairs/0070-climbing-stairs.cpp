class Solution {
public:

// Recursive function with memoization
int solve(int n, vector<int> &dp){

    // Base cases
    if(n == 0) return 1;
    if(n == 1) return 1;

    // If already computed, return stored value
    if(dp[n] != -1)
        return dp[n];

    // Store and return result
    return dp[n] = solve(n-1, dp) + solve(n-2, dp);
}

int climbStairs(int n) {

    // dp array initialize with -1
    vector<int> dp(n+1, -1);

    return solve(n, dp);
}
};
