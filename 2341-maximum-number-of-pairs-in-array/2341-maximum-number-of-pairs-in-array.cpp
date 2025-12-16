class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {

        // Map to store frequency of each number
        map<int,int> mp;
        for(int num : nums)
            mp[num]++;

        // ans[0] -> number of pairs
        // ans[1] -> number of leftover elements
        vector<int> ans(2);

        int cnt1 = 0, cnt2 = 0;

        // Traverse frequency map
        for(auto &it : mp){
            cnt1 += it.second / 2;   // pairs
            cnt2 += it.second % 2;   // leftovers
        }

        ans[0] = cnt1;
        ans[1] = cnt2;
        return ans;
    }
};
