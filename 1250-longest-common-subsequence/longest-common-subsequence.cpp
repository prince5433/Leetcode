class Solution {
public:
    //2 parameetrs change ho rhe haui and j to we use 2d dp
    vector<vector<int>> dp;
    int f(string& s1,string& s2,int i,int j){
        //i for s1 and j for s2
        //base cases
        if(i>=s1.size()) return 0;
        if(j>=s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            return dp[i][j]= 1+f(s1,s2,i+1,j+1);
        } else{
            return dp[i][j]=max(f(s1,s2,i+1,j),f(s1,s2,i,j+1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.clear();
        dp.resize(1005,vector<int>(1005,-1));
        return f(text1,text2,0,0);
    }
};