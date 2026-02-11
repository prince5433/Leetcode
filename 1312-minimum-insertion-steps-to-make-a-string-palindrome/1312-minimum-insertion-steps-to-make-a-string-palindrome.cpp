class Solution {
public:
vector<vector<int>>dp;

// LCS function (Top-down DP with memoization)
// i -> index for s1
// j -> index for s2
int LCS(string& s1,string& s2,int i,int j){
        
        // Base case:
        // Agar kisi bhi string ka end aa gaya
        // to LCS possible nahi hai
        if(i>=s1.size()) return 0;
        if(j>=s2.size()) return 0;

        // Agar already computed hai to direct return karo
        if(dp[i][j]!=-1) return dp[i][j];

        // Agar characters match karte hain
        // to 1 + next diagonal call
        if(s1[i]==s2[j]){
            return dp[i][j]= 1+LCS(s1,s2,i+1,j+1);
        } 
        else{
            // Agar match nahi karte
            // to max lo:
            // skip from s1 OR skip from s2
            return dp[i][j]=max(
                LCS(s1,s2,i+1,j),
                LCS(s1,s2,i,j+1)
            );
        }
    }

    int minInsertions(string s) {

        int n=s.size();

        // Clear previous dp values
        dp.clear();

        // Resize dp to 501x501 and fill with -1
        dp.resize(501, vector<int>(501, -1));   

        // Reverse string banaya
        string rev = s;
        reverse(rev.begin(), rev.end());

        // LCS of original and reversed string
        // gives Longest Palindromic Subsequence
        int lcs =LCS(s,rev,0,0);

        // Minimum insertions = n - LPS
        return s.size()-lcs;
    }
};
