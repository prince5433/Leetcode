class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=logs.size();
       sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
        });
        vector<pair<int,int>> queri;
       for(int i=0;i<queries.size();i++){
        queri.push_back({queries[i],i});
       }
       sort(queri.begin(),queri.end());
       vector<int> ans(queries.size(),0);

        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        for(auto& q:queri){
            int time = q.first;
            int idx = q.second;
            int s=time-x;
            int e=time;

            while(j<m &&logs[j][1]<=e ){
                mp[logs[j][0]]++;
                j++;
            }
            while(i<j && logs[i][1]<s){
                mp[logs[i][0]]--;
                if(mp[logs[i][0]]==0) mp.erase(logs[i][0]);
                i++;
            }
            ans[idx]=n-mp.size();
        }
        return ans;
    }
};