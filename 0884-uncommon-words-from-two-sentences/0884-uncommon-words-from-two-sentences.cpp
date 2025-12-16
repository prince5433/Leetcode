class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
          unordered_map<string,int>mp1;
          stringstream ss(s1);
          string temp;
          while(ss>>temp){
            mp1[temp]++;
          }
            stringstream sp(s2);
          string temp1;
          while(sp>>temp1){
            mp1[temp1]++;
          }
          vector<string> ans;

          for(auto& it:mp1){
            if(it.second==1){
                ans.push_back(it.first);
            }
          }
          return ans;
    }
};