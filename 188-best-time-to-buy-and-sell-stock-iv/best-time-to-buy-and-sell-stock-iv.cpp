class Solution {
public:
int dp[1005][105][2];//i k on
int f(vector<int>& prices,int i,int k,bool on){
    //base case
    if(i==prices.size()) return 0;//last e aagaye to 0 profit
    if(dp[i][k][on]!=-1) return dp[i][k][on];
    int ans=INT_MIN;
    ans=f(prices,i+1,k,on);//avoid kr diya ith stock , na buy n sell
    //not avoid
    if(on){//on true mtlb buy kr chuke hai then we have to sell 
        ans=max(ans,prices[i]+f(prices,i+1,k-1,false));//sell kiya to profit aya ,k-- huwa ,i+1 jayenge,and and ab buy krna hai to on Ko false kr diya
    } else{//on false hai mtlb sell kr chuke then buy but k hona chahiy
        if(k>0){
            ans=max(ans,f(prices,i+1,k,true)-prices[i]);
            //buy kiya to i+!1,k same it changes in complete transaction buy and sell ,on ko true kiya and profit i cost laga in buying that stock
        }
    }
    return dp[i][k][on]=ans;
}
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(prices,0,k,false);
    }
};