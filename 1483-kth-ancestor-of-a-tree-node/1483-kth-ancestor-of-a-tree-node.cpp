class TreeAncestor {
public:

    /*
    Binary Lifting Table

    ancestorNode[node][j]

    stores:

    2^j-th ancestor of node
    */
    vector<vector<int>> ancestorNode;

    int rows;
    int cols;

    TreeAncestor(int n, vector<int>& parent) {

        rows = n;

        /*
        Maximum power needed.

        Example:

        n = 8

        log2(8)+1 = 4

        Powers:
        2^0,2^1,2^2,2^3
        */
        cols = log2(n) + 1;

        // Initialize lifting table
        ancestorNode.resize(
            rows,
            vector<int>(cols, -1)
        );

        /*
        First column:

        ancestorNode[node][0]
        = immediate parent
        */
        for(int node = 0; node < n; node++) {
            ancestorNode[node][0] = parent[node];
        }

        /*
        Build Binary Lifting Table

        Formula:

        ancestor[node][j]

        = 2^j-th ancestor

        = 2^(j-1) ancestor of

          2^(j-1) ancestor
        */
        for(int j = 1; j < cols; j++) {

            for(int node = 0; node < n; node++) {

                /*
                If 2^(j-1) ancestor exists
                */
                if(ancestorNode[node][j - 1] != -1) {

                    ancestorNode[node][j] =
                        ancestorNode[
                            ancestorNode[node][j - 1]
                        ][j - 1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {

        /*
        Intuition:

        Represent k in binary.

        Example:

        k = 13

        Binary:
        1101

        = 8 + 4 + 1

        So move:

        2^3 ancestor
        +
        2^2 ancestor
        +
        2^0 ancestor
        */

        for(int j = 0; j < cols; j++) {

            // If j-th bit is set
            if(k & (1 << j)) {

                node = ancestorNode[node][j];

                // Ancestor doesn't exist
                if(node == -1)
                    return -1;
            }
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

/*
---------------- QUICK INTUITION ----------------

Binary Lifting

Instead of moving
one parent at a time:

node -> parent -> grandparent ...

we jump in powers of 2.

------------------------------------------------

Example:

Tree:

0
|
1
|
2
|
3
|
4

For node = 4

ancestor[4][0] = 3   (1 step)
ancestor[4][1] = 2   (2 steps)
ancestor[4][2] = 0   (4 steps)

------------------------------------------------

Why Formula Works?

Need 2^j ancestor.

Example:

2^3 ancestor = 8th ancestor

Can be found as:

4th ancestor of
4th ancestor

So:

ancestor[node][j]

=

ancestor[
    ancestor[node][j-1]
][j-1]

------------------------------------------------

Query Example:

Find 13th ancestor.

13 = (1101)₂

= 8 + 4 + 1

Jump:

2^3
+
2^2
+
2^0

Instead of 13 moves,
only log(k) moves.

------------------------------------------------

TC:

Preprocessing:

n * log(n)

O(n log n)

------------------------------------------------

Query:

Loop over log(n) columns

O(log n)

------------------------------------------------

SC:

Binary Lifting Table

O(n log n)

------------------------------------------------

Pattern:

Binary Lifting
Jump Pointers
Trees
K-th Ancestor Queries
*/