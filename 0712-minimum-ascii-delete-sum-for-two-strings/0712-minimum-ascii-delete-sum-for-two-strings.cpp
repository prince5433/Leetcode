class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, string &s1, string &s2) {
        // If both strings are finished → no cost
        if (i == s1.size() && j == s2.size())
            return 0;

        // If s1 finished → delete remaining chars of s2
        if (i == s1.size())
            return s2[j] + solve(i, j + 1, s1, s2);

        // If s2 finished → delete remaining chars of s1
        if (j == s2.size())
            return s1[i] + solve(i + 1, j, s1, s2);

        // Already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        // If characters match → no delete, move both
        if (s1[i] == s2[j])
            return dp[i][j] = solve(i + 1, j + 1, s1, s2);

        // Else delete one character (choose min cost)
        int deleteFromS1 = s1[i] + solve(i + 1, j, s1, s2);
        int deleteFromS2 = s2[j] + solve(i, j + 1, s1, s2);

        return dp[i][j] = min(deleteFromS1, deleteFromS2);
    }

    int minimumDeleteSum(string s1, string s2) {
        dp.assign(s1.size(), vector<int>(s2.size(), -1));
        return solve(0, 0, s1, s2);
    }
};
