
class Solution {
public:

    // DSU - FIND with Path Compression
    int find(vector<int> &parent, int x) {

        if(parent[x] == x) return x;

        return parent[x] = find(parent, parent[x]);
    }


    // DSU - UNION by Rank
    void Union(vector<int> &parent, vector<int> &rank, int a, int b) {

        a = find(parent, a);
        b = find(parent, b);

        if(a == b) return;

        if(rank[a] <= rank[b]) {
            parent[a] = b;
            rank[b]++;
        } 
        else {
            parent[b] = a;
            rank[a]++;
        }
    }


    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        // Step 1: Create all possible edges.
        // Format: {weight, u, v}
        vector<vector<int>> edges;

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                // Calculate Manhattan Distance.
                int wt = abs(points[i][0] - points[j][0])
                       + abs(points[i][1] - points[j][1]);

                edges.push_back({wt, i, j});
            }
        }


        // Step 2: Sort edges by increasing weight.
        sort(edges.begin(), edges.end());


        // Step 3: Initialize DSU.
        vector<int> parent(n);
        vector<int> rank(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }


        // Step 4: Apply Kruskal's Algorithm.
        int ans = 0;
        int edgeCount = 0;

        for(auto &e : edges) {

            int wt = e[0];
            int u = e[1];
            int v = e[2];

            // Check whether both points belong to different components.
            if(find(parent, u) != find(parent, v)) {

                // Merge both components using your Union function.
                Union(parent, rank, u, v);

                // Add selected edge weight to MST cost.
                ans += wt;

                // One edge has been selected.
                edgeCount++;

                // MST requires exactly n-1 edges.
                if(edgeCount == n - 1)
                    break;
            }
        }

        return ans;
    }
};


/*
TIME COMPLEXITY:

Creating edges = O(n^2)
Sorting edges = O(n^2 log n)
DSU operations = O(n^2 * alpha(n))

Overall TC = O(n^2 log n)


SPACE COMPLEXITY:

Edges = O(n^2)
Parent = O(n)
Rank = O(n)

Overall SC = O(n^2)
*/
