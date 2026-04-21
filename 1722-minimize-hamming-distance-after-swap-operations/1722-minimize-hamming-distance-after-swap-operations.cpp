
class Solution {
public:
    // ✅ Tumhara FIND function (Path Compression)
    int find(vector<int> &parent, int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent, parent[x]);
    }

    // ✅ Tumhara UNION function (Union by Rank)
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

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        
        // Step 1: DSU setup (exactly like your Kruskal's initialization)
        vector<int> parent(n);
        vector<int> rank(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i; 
        }

        // Step 2: Connections banana (Allowed swaps process karna)
        for (auto& swap : allowedSwaps) {
            Union(parent, rank, swap[0], swap[1]);
        }

        // Step 3: Grouping elements
        // Har component ke liye ek map banayenge jo elements ki frequency rakhega
        // unordered_map<RootIndex, unordered_map<ElementValue, Count>>
        unordered_map<int, unordered_map<int, int>> groupPool;
        for (int i = 0; i < n; i++) {
            int root = find(parent, i);
            groupPool[root][source[i]]++;
        }

        int hammingDist = 0;

        // Step 4: Target array ke elements ko check karna
        for (int i = 0; i < n; i++) {
            int root = find(parent, i);
            int requiredVal = target[i];

            // Agar hamare pass us group ke pool mein wo element hai
            if (groupPool[root][requiredVal] > 0) {
                groupPool[root][requiredVal]--; // Use kar liya
            } else {
                // Nahi hai toh mismatch!
                hammingDist++;
            }
        }

        return hammingDist;
    }
};