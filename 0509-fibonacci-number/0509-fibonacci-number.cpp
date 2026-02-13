class Solution {
public:

// Bottom-up DP (Tabulation) function
// dp[i] store karega ith Fibonacci number
int fibo(int n, vector<int> &dp){

    // Base case:
    // fib(0) = 0
    // fib(1) = 1
    if(n <= 1) 
        return n;

    // Initialize base values in dp array
    dp[0] = 0;
    dp[1] = 1;

    // Build Fibonacci values from 2 to n
    // using previously computed values
    for(int i = 2; i <= n; i++){

        // Fibonacci relation:
        // fib(i) = fib(i-1) + fib(i-2)
        dp[i] = dp[i-1] + dp[i-2];
    }

    // Return nth Fibonacci number
    return dp[n];
}

int fib(int n) {

    // Create dp array of size n+1
    // dp[i] will store ith Fibonacci number
    vector<int> dp(n+1);

    // Call bottom-up function
    return fibo(n, dp);
}
};
