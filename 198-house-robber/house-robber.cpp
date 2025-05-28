class Solution {
public:
int f(vector<int> arr,int i,vector<int>& dp){
    if(i==arr.size()-1) return arr[i];
    if(i==arr.size()-2) return max(arr[i],arr[i+1]);
    if(dp[i]!=-1) return dp[i];
    return dp[i]=max((arr[i]+f(arr,i+2,dp)),(0+f(arr,i+1,dp)));
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return f(nums,0,dp);
    }
};