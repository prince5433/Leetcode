class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size()/2;
        sort(nums.begin(),nums.end());
        for(int i=0;i<2*n-1;i++){
            if(nums[i]==nums[i+1]) return nums[i];
        }
        return 0;
    }
};