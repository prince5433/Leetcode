class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        if(mini==maxi) return 0;
        int cm=0,cma=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi) cma++;
            else if(nums[i]==mini) cm++;
        }
        return nums.size()-(cm+cma);
    }
};