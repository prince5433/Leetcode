class Solution {
public:
    // DSU Find with Path Compression
    int find(vector<int>& parent, int x) {

        // Root node found
        if (parent[x] == x)
            return x;

        /*
        Path Compression

        Directly connect node
        to ultimate parent.
        */
        return parent[x] = find(parent, parent[x]);
    }

    // DSU Union by Rank
    void Union(vector<int>& parent, vector<int>& rank, int a, int b) {

        // Find ultimate parents
        a = find(parent, a);
        b = find(parent, b);

        // Already connected
        if (a == b)
            return;

        /*
        Attach smaller rank tree
        under larger rank tree.
        */
        if (rank[a] <= rank[b]) {

            parent[a] = b;

            rank[b]++;
        } else {

            parent[b] = a;

            rank[a]++;
        }
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {

        /*
        Kruskal's Algorithm

        Sort edges by weight.
        */
        sort(edges.begin(), edges.end(),
             [](const vector<int>& e1, const vector<int>& e2) {
                 return e1[2] < e2[2];
             });

        vector<int> parent(n);

        vector<int> rank(n, 1);

        // Initially every node is separate
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        /*
        Initially:

        n nodes
        => n components
        */
        int components = n;

        for (auto& e : edges) {

            int u = e[0];
            int v = e[1];
            int wt = e[2];

            int parentu = find(parent, u);
            int parentv = find(parent, v);

            // Edge connects different components
            if (parentu != parentv) {

                Union(parent, rank, u, v);

                components--;
            }

            /*
            First time when
            components become k

            Current edge weight
            is the answer.
            */
            if (components == k) {
                return wt;
            }
        }

        return 0;
    }
};

/*
---------------- QUICK INTUITION ----------------

This is Kruskal + DSU.

------------------------------------------------

Initially:

n nodes

All separate.

Example:

1   2   3   4

Components = 4

------------------------------------------------

Sort edges by weight.

Always connect cheapest edge first.

Exactly same idea as MST.

------------------------------------------------

Example:

Edges:

1-2 (2)
2-3 (4)
3-4 (7)

k = 2

Start:

Components = 4

Take edge wt=2

Components = 3

Take edge wt=4

Components = 2

Reached k components.

Answer = 4

------------------------------------------------

Why return current weight?

Kruskal me hum smallest edges
add karte ja rahe.

Jab components exactly k bante hain,

current edge is the largest edge
used till now.

That becomes minimum possible cost.

------------------------------------------------

DSU Operations

find():
Find ultimate parent.

Union():
Merge two components.

------------------------------------------------

TC:

Sorting:
O(E log E)

DSU Operations:
O(E * α(N))

Overall:
O(E log E)

------------------------------------------------

SC:

parent[] -> O(N)

rank[] -> O(N)

Total:
O(N)

------------------------------------------------

Pattern:

DSU
Union Find
Kruskal Algorithm
Minimum Spanning Tree
*/