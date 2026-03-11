class Solution {
public:
int n,m;
int dp[501][501];
int solve(vector<int>& nums1, vector<int>& nums2,int i,int j){
    if(i==n || j==m) return -1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int product=nums1[i]*nums2[j];
    int take_both=product+solve(nums1,nums2,i+1,j+1);
    int take_i=solve(nums1,nums2,i,j+1);
    int take_j=solve(nums1,nums2,i+1,j);

    return dp[i][j]= max({product,take_both,take_i,take_j});
}
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        n=nums1.size();
        m=nums2.size();
        return solve(nums1,nums2,0,0);
    }
};