class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> ans;
        map<int,int>mp;
        for(int num:bulbs)mp[num]++;
        for(auto it:mp){
            if(it.second%2!=0){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};