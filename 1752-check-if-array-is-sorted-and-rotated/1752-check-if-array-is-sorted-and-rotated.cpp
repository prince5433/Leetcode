class Solution {
public:
    bool check(vector<int>& nums) {
         int n=nums.size();
         int pvt=-1;
         for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                pvt=i;
            }
         }
         if(pvt==-1) return true;
         reverse(nums.begin(),nums.begin()+pvt+1);
         reverse(nums.begin()+pvt+1,nums.end());
         reverse(nums.begin(),nums.end());
        bool flag =true;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])
                flag=false; 
        }
        return flag;
    }
};