class Solution {
public:
bool isSorted(vector<int>& nums){
    for(int i=1;i<nums.size();i++){
        if(nums[i]<nums[i-1]) return false;
    }
    return true;
}
    int minimumPairRemoval(vector<int>& nums) {
        int ops=0;
        while(!isSorted(nums)){
            int idx=0;
            int mn=nums[0]+nums[1];
            for(int i=1;i<nums.size()-1;i++){
                if(nums[i]+nums[i+1]<mn){
                    mn=nums[i]+nums[i+1];
                    idx=i;
                }
            }
            nums.erase(nums.begin()+idx);
            nums[idx]=mn;
            ops++;
        }
        return ops;
    }
};