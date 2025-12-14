class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
         sort(nums.rbegin(),nums.rend());
        int sum1=0;
        for(int i=0;i<k;i++){
            sum1+=nums[i];
        }
        return abs(sum-sum1);
        

    }
};