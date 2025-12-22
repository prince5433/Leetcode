class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int odd=1,even=0;
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int num:nums){
            if(num%2==0){
                ans[even]=num;
                even+=2;
            } else {
                ans[odd]=num;
                odd+=2;
            }
        }
        return ans;
    }
};