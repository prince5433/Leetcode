class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i+1;j<n;j++){
                if(nums[i]%2==0){
                    if(nums[j]%2==1) cnt++;
                } else {
                    if(nums[j]%2==0) cnt++;
                }
            }
            ans[i]=cnt;
        }
        return ans;
    }
};