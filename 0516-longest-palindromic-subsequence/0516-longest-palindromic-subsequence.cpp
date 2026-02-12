class Solution {
public:

vector<vector<int>> dp;   // 2D dp table for memoization
                         // dp[i][j] = longest palindromic subsequence
                         // in substring s[i...j]

// Recursive function to compute LPS
int lps(string &s, int i, int j){

    // Base Case 1:
    // Agar i cross kar gaya j ko
    // matlab empty substring
    if(i > j) return 0;

    // Base Case 2:
    // Single character always palindrome of length 1
    if(i == j) return 1;

    // Agar state already computed hai
    // to directly dp se return karo
    if(dp[i][j] != -1) 
        return dp[i][j];

    // Agar dono characters match karte hain
    if(s[i] == s[j]){

        // Dono characters include kar sakte hain
        // isliye 2 + andar ka result
        return dp[i][j] = 2 + lps(s, i+1, j-1);
    } 
    else {

        // Agar match nahi karte
        // to ek character skip karna padega
        // left skip ya right skip
        // dono me se maximum lo
        return dp[i][j] = max(
            lps(s, i+1, j),
            lps(s, i, j-1)
        );
    }
}

int longestPalindromeSubseq(string s) {

        int n = s.size();

        dp.clear();  // dp table clear kar diya

        // n x n dp table initialize with -1
        dp.resize(n, vector<int>(n, -1));

        // pura string consider kar rahe hain
        return lps(s, 0, n-1);
    }
};
