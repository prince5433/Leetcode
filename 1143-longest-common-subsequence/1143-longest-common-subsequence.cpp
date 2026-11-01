class Solution {
public:
    vector<vector<int>> dp;

    int f(string& s1, string& s2, int i, int j) {

        // i = current index in s1
        // j = current index in s2

        // BASE CASE 1:
        // Agar s1 complete ho gayi, toh common subsequence
        // ke liye aur characters available nahi hain.
        if(i >= s1.size())
            return 0;

        // BASE CASE 2:
        // Agar s2 complete ho gayi, toh bhi common subsequence
        // mein aur characters add nahi kar sakte.
        if(j >= s2.size())
            return 0;

        // Agar current state (i, j) already calculate hai,
        // toh stored answer return karo.
        if(dp[i][j] != -1)
            return dp[i][j];

        // CASE 1: Dono strings ke current characters match karte hain.
        if(s1[i] == s2[j]) {

            // Matching character ko LCS mein include karo.
            // Dono strings mein next index par move karo.
            return dp[i][j] = 1 + f(s1, s2, i + 1, j + 1);

        } 
        else {

            // CASE 2: Characters match nahi karte.

            // OPTION 1: s1 ka current character skip karo.
            int skipS1 = f(s1, s2, i + 1, j);

            // OPTION 2: s2 ka current character skip karo.
            int skipS2 = f(s1, s2, i, j + 1);

            // Dono options mein se maximum LCS length choose karo.
            return dp[i][j] = max(skipS1, skipS2);
        }
    }

    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();

        // DP dimensions strings ki actual lengths ke according.
        dp.resize(n, vector<int>(m, -1));

        // Starting indices dono strings ke 0 hain.
        return f(text1, text2, 0, 0);
    }
};

// TC: O(N * M) — Har (i, j) state maximum ek baar calculate hoti hai.
// SC: O(N * M) — DP table + O(N + M) recursion stack.