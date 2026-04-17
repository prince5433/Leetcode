class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int cnt=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int el=nums[i];
            auto it=upper_bound(nums.begin(),nums.end(),el);
            int pos=it-nums.begin();
            int greater=n-pos;
            if(greater>=k) cnt++;
        }
        return cnt;
    }
};