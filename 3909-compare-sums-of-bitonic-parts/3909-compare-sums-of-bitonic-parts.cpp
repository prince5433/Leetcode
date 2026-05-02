class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n=nums.size();
        int idx=-1;
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                idx=i;
                break;
            }
        }
        long long asc=0;
        long long desc=0;
        for(int i=0;i<=idx;i++){
            asc+=nums[i];
        }
        for(int i=idx;i<n;i++){
            desc+=nums[i];
        }
        if(asc>desc) return 0;
        else if(desc>asc) return 1;
        else return -1;
    }
};