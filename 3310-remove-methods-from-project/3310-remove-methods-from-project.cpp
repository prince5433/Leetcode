class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int>inDegree(n,0);
        vector<bool> suspicious(n,false);

        for(auto &edge:invocations){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        //bfs 
        queue<int> qu;
        qu.push(k);
        suspicious[k]=true;
        while(!qu.empty()){
            int curr=qu.front();
            qu.pop();
            for(auto& ngbr:adj[curr]){
                inDegree[ngbr]--;
                if(!suspicious[ngbr]){
                    qu.push(ngbr);
                    suspicious[ngbr]=true;
                }
            }
        }
        vector<int> result;
        bool cannotremove=false;
        for(int i=0;i<n;i++){
            if(suspicious[i]&& inDegree[i]>0){
                cannotremove=true;
                break;
            }
            if(!suspicious[i]){
                result.push_back(i);
            }
        }
        if(cannotremove){
            vector<int> vec(n);
            for(int i=0;i<n;i++){
                vec[i]=i;
            }
            return vec;
        }
        return result;
    }
};