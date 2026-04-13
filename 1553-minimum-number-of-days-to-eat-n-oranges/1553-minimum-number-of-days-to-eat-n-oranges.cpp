class Solution {
public:
    // 🔹 Map is used because n is up to 2*10^9. 
    // Array would cause Memory Limit Exceeded (MLE).
    unordered_map<int, int> dp;

    int minDays(int n) {
        // Base case: 0 oranges = 0 days, 1 orange = 1 day
        if (n <= 2) return n;

        // Memoization check
        if (dp.count(n)) return dp[n];

        /* 💡 DEEP INTUITION:
           Humein 3 choices milti hain:
           1. 1 orange khao.
           2. Half khao (agar even hai).
           3. 2/3 khao (agar 3 se divisible hai).

           🔥 THE TRICK: 
           Humein 'n-1' wala rasta direct nahi lena chahiye kyunki wo O(n) ho jayega.
           Hum 'n%2' ya 'n%3' oranges khao taaki number 2 ya 3 se divide ho sake.
           
           Example: Agar n=10 hai, n%3 = 1. Matlab 1 orange kha kar ise 9 banao (1 day), 
           phir 9 ko 3 se divide kar do (another 1 day). Total = 1 + 1 + minDays(3).
        */

        return dp[n] = 1 + min(
            (n % 2) + minDays(n / 2), // Make it even then divide by 2
            (n % 3) + minDays(n / 3)  // Make it multiple of 3 then divide by 3
        );
    }
};