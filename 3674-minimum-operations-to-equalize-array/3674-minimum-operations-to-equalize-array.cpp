class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
      int i=0;
      while(i<n-1){
            if(nums[i]==nums[i+1]){
                i++;
            }
            else {
                break;
            }
        }
        if(i==n-1) return 0;
        else return 1;
    }
};