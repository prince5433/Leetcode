class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int tgt=nums[n-1];
        int ops=0;
        for(int i=0;i<n;i++){
            ops+=abs(nums[i]-tgt);
        }
        return ops;
    }
};