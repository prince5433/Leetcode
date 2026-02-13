class Solution {
public:

// Recursive function with memoization
// dp[n] store karega nth Fibonacci number
int solve(int n, vector<int> &dp){

    // Base case:
    // fib(0) = 0
    // fib(1) = 1
    if(n <= 1)
        return n;

    // Agar already calculate ho chuka hai
    // to dp se directly return karo
    if(dp[n] != -1)
        return dp[n];

    // Recursive relation:
    // fib(n) = fib(n-1) + fib(n-2)
    // aur result dp me store kar do
    return dp[n] = solve(n-1, dp) + solve(n-2, dp);
}

int fib(int n) {

    // dp array initialize with -1
    // -1 means not calculated yet
    vector<int> dp(n+1, -1);

    // Call recursive memo function
    return solve(n, dp);
}
};
