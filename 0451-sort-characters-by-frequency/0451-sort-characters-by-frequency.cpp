class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
          auto top=pq.top();pq.pop();
          int count=top.first;
          char ch=top.second;
          ans.append(count,ch);
        }
        
        return ans;
    }
};