class Solution {
public:
    vector<vector<int>> dp;

    // Intuition:
    // Minimum insertions to make a string palindrome =
    // Length of string - Longest Palindromic Subsequence (LPS)
    //
    // Why?
    // Because characters already forming a palindrome (LPS) don't need changes.
    // Only the remaining characters must be inserted appropriately.
    //
    // LPS can be found by computing:
    // LCS(original_string, reversed_string)

    // LCS function (Top-down DP with memoization)
    // i -> current index in s1
    // j -> current index in s2
    int LCS(string& s1, string& s2, int i, int j){

        // Base Case:
        // If we reach the end of any string,
        // no more common subsequence can be formed
        if(i >= s1.size()) return 0;
        if(j >= s2.size()) return 0;

        // If this state already computed, return stored value
        if(dp[i][j] != -1) return dp[i][j];

        // Case 1: Characters match
        // Include this character in LCS and move both pointers
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + LCS(s1, s2, i+1, j+1);
        }
        else{
            // Case 2: Characters don't match
            // Either skip character from s1 OR skip from s2
            // and take the maximum LCS possible
            return dp[i][j] = max(
                LCS(s1, s2, i+1, j),
                LCS(s1, s2, i, j+1)
            );
        }
    }

    int minInsertions(string s) {

        int n = s.size();

        // Clear any previous dp values
        dp.clear();

        // Initialize dp table with -1
        // dp[i][j] stores LCS length starting from s1[i], s2[j]
        dp.resize(501, vector<int>(501, -1));

        // Create reversed version of the string
        string rev = s;
        reverse(rev.begin(), rev.end());

        // LCS between original string and reversed string
        // gives Longest Palindromic Subsequence (LPS)
        int lcs = LCS(s, rev, 0, 0);

        // Minimum insertions required =
        // characters not part of palindrome
        return n - lcs;
    }
};