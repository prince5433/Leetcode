class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>lmax(n);
        vector<int> rmax(n);
        for(int i=1;i<n;i++){
            lmax[i]=max(nums[i-1],lmax[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            rmax[i]=max(nums[i+1],rmax[i+1]);
        }

        vector<int> ans;

        for(int i = 0; i < n; i++) {
            if(i == 0 || i == n-1 || nums[i] > lmax[i] || nums[i] > rmax[i]) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};
  