class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
    int maxidx=-1;
    int maxi=-1;
    for(int i=0;i<n;i++){
        if(nums[i]>maxi){
            maxi=nums[i];
            maxidx=i;
        }
    }
    sort(nums.begin(),nums.end());
    if(nums[n-1]>=2*nums[n-2]) return maxidx;
    else return -1;
    }
};