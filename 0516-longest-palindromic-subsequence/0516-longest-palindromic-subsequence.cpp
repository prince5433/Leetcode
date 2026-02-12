class Solution {
public:
vector<vector<int>> dp;   // 2D dp table for memoization

// LCS function (Top Down)
int lcs(string &s1, string& s2, int i, int j){

     // Base case:
     // Agar kisi bhi string ka end aa gaya
     // to LCS 0 hoga
     if(i >= s1.size()) return 0;
     if(j >= s2.size()) return 0;

     // Agar state pehle compute ho chuki hai
     // to directly dp se return kar do
     if(dp[i][j] != -1) 
         return dp[i][j];

     // Agar characters match karte hain
     // to 1 add karo aur dono pointers aage badhao
     if(s1[i] == s2[j]){
         return dp[i][j] = 1 + lcs(s1, s2, i+1, j+1);
     } 
     else{
         // Agar match nahi karte
         // to do possibilities:
         // 1. s1 ka current character skip karo
         // 2. s2 ka current character skip karo
         // dono me se maximum lo
         return dp[i][j] = max(
             lcs(s1, s2, i+1, j),
             lcs(s1, s2, i, j+1)
         );
     }
}

int longestPalindromeSubseq(string s) {

        // rev me original string store kar rahe hain
        string rev = s;

        // s ko reverse kar diya
        // ab s = reversed string
        reverse(s.begin(), s.end());

        dp.clear();   // dp table clear kar diya

        int n = s.size();

        // dp table initialize kar rahe hain
        // size n x n and fill with -1
        dp.resize(n, vector<int>(n, -1));

        // LCS of reversed string and original string
        // same as Longest Palindromic Subsequence
        return lcs(s, rev, 0, 0);
    }
};
