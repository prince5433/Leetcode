class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string,int> mp;
        int n=responses.size();
        for(auto it:responses){
           set<string> seen;
           for(string str:it){
            seen.insert(str);
           }
           for(auto i:seen) mp[i]++;
        }
        string ans="";
        int maxi=0;
        for(auto c:mp){
           if(c.second>maxi){
            maxi=c.second;
            ans=c.first;
           }
        }
        return ans;
    }
};