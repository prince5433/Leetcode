class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=accumulate(nums.begin(),nums.end(),0);
        return ans%k;
    }
};