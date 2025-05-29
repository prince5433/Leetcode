#define mod 1000000007

class Solution {
public:
vector<vector<int>> dp;
int f(int n,int k, int t){
    if(n==0 && t==0) return 1;//dice khatam and taregt achieved to 1
    if(n==0) return 0;//dice khatam but target not achieved to 0;

    //change ho rhe ha n and t to 2d dp lagegi
    if(dp[n][t]!=-1) return dp[n][t];

    int sum=0;
    for(int v=1;v<=k && t-v>=0;v++){
        sum=(sum%mod+f(n-1,k,t-v)%mod)%mod;
    }
    return dp[n][t]=sum%mod;
}
    int numRollsToTarget(int n, int k, int target) {
        dp.clear();
        dp.resize(35,vector<int> (1005,-1));
        return f(n,k,target);
    }
};