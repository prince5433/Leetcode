class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        if(n<=2) return {-1,-1};
        map<int,int> mp;
        for(int num:nums) mp[num]++;
        sort(nums.begin(),nums.end());
        ans.push_back(nums[0]);
        int comp=nums[0];
        int val=-1;
        for(auto it:mp){
            if(it.first==comp){
                val=it.second;
            }
        }
        for(auto it:mp){
            if(it.second!=val){
                 ans.push_back(it.first);
                 return ans;
            }
        }
        return {-1,-1};
    }
};