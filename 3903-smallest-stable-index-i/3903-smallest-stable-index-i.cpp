class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pmax(n);
        vector<int> pmin(n);
        pmax[0]=nums[0];
        pmin[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pmax[i]=max(pmax[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            pmin[i]=min(pmin[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            if(pmax[i]-pmin[i]<=k){
                return i;
            }
        }
        return -1;
    }
};