class Solution {
public:
    // Modular exponentiation
    long long power(long long base, long long exp, int mod) {
        if (exp == 0) return 1;
        
        long long half = power(base, exp / 2, mod);
        long long res = (half * half) % mod;
        
        if (exp % 2 == 1) {
            res = (res * base) % mod; 
        }
        return res;
    }

    // DFS with visited array
    void dfs(int node, int depth, vector<bool>& visited, vector<vector<int>>& adj, int& maxdepth) {
        visited[node] = true;
        maxdepth = max(maxdepth, depth);
        
        for (auto neigh : adj[node]) {
            if (!visited[neigh]) {
                dfs(neigh, depth + 1, visited, adj, maxdepth); 
            }
        }
    }

    // YAHAN NAAM FIX KIYA HAI: assignEdgeWeights
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1; 
        
        vector<vector<int>> adj(n + 1);
        
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]); 
        }
        
        int maxdepth = 0;
        vector<bool> visited(n + 1, false); 
        
        dfs(1, 0, visited, adj, maxdepth);
        
        const int MOD = 1e9 + 7;
        if (maxdepth == 0) return 0;
        
        return power(2, maxdepth - 1, MOD); 
    }
};