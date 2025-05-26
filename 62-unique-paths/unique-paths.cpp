class Solution {
public:
    int helper(int sr,int sc,int er,int ec ,vector<vector<int>>& dp){
        if(sr==er && sc==ec) return 1;//1 path to hai aisa
        if(sr>er || sc>ec) return 0 ;
        //jo cheej change ho rhi hai use memoize kro 
        if(dp[sr][sc]!=-1) return dp[sr][sc];
        return dp[sr][sc]=helper(sr,sc+1,er,ec,dp)+helper(sr+1,sc,er,ec,dp);//downways +rightways
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(0,0,m-1,n-1,dp);
    }
};