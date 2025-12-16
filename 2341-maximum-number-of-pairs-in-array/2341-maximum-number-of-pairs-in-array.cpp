class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int,int> mp;
        for(int num:nums)mp[num]++;
        vector<int> ans(2);
        int cnt1,cnt2=0;
        for(auto &it:mp){
           cnt1+=it.second/2;
           cnt2+=it.second%2;
        }
        ans[0]=cnt1;
        ans[1]=cnt2;
        return ans;
    }
};