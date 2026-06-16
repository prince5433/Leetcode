class Solution {
public:
int find(vector<int> &parent, int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent, parent[x]);
    }

    // ✅ Tumhara DSU UNION by rank function
    void Union(vector<int> &parent, vector<int> &rank, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);

        if (a == b) return;

        if (rank[a] <= rank[b]) {
            parent[a] = b;
            rank[b]++;  
        } else {
            parent[b] = a;
            rank[a]++;
        }
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {
        sort(edges.begin(),edges.end(),[](const vector<int>& e1, const vector<int>& e2) {
            return e1[2] < e2[2];
        });
        vector<int> parent(n);
        vector<int> rank(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int components=n;
        for(auto& e:edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];

            int parentu=find(parent,u);
            int parentv=find(parent,v);
            if(parentu!=parentv){
                Union(parent,rank,u,v);
                components--;
            }
            if(components==k){
                return wt;
            }
        }
           return 0;
    }
     
    
};