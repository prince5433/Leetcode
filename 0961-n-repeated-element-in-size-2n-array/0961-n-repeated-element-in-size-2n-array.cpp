class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size()/2;
        map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        for(auto it:mp){
            if(it.second==n)return it.first;
        }
        return 0;
    }
};