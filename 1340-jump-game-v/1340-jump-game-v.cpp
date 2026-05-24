class Solution {
public:
    int n;
    vector<int> dp;

    int solve(vector<int>& arr, int i, int d) {

        /*
        Intuition:
        solve(i) = max jumps possible starting from index i

        From i, we can jump:
        left  -> i-1 ... i-d
        right -> i+1 ... i+d

        Condition:
        Only smaller height pe jump kar sakte.
        */
        
        if (dp[i] != -1) return dp[i];   // memoized answer

        int result = 1; // at least current index

        // Check left side
        for (int j = i - 1; j >= max(0, i - d); j--) {

            /*
            Agar bigger/equal height mila,
            aage jump block ho jayega.
            */
            if (arr[j] >= arr[i]) break;

            result = max(result, 1 + solve(arr, j, d));
        }

        // Check right side
        for (int j = i + 1; j <= min(n - 1, i + d); j++) {

            // Jump blocked
            if (arr[j] >= arr[i]) break;

            result = max(result, 1 + solve(arr, j, d));
        }

        return dp[i] = result;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();

        dp.clear();
        dp.resize(n + 1, -1); // memo

        int result = 1;

        /*
        Har index ko starting point maan ke
        max path nikal rahe.
        */
        for (int i = 0; i < n; i++) {
            result = max(result, solve(arr, i, d));
        }

        return result;
    }
};

/*
Quick Idea:
DFS + DP (Memoization)

Har index se left/right d range me jump try karo.
Sirf smaller element pe jump allowed.
DP stores max jumps from each index.

TC:
O(n * d)
(each index once, left+right d tak)

SC:
O(n)
dp + recursion stack

Pattern:
DP + DFS
Memoization
Recursion
*/