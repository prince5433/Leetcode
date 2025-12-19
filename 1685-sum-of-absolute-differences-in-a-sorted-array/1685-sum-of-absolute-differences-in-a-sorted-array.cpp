class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int ts=0;
        for(int x:nums) ts+=x;
        int leftsum=0;
        for(int i=0;i<n;i++){
            int left=((i*nums[i])-leftsum);
            int right=((ts-leftsum-nums[i])-(n-i-1)*nums[i]);
            ans[i]=left+right;
            leftsum+=nums[i];
        }
        return ans;
    }
};