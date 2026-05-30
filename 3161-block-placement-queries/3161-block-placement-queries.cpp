class Solution {
public:

    // Segment Tree stores maximum gap information
    vector<int> segmentTree;

    // Maximum coordinate limit
    int n = 50000;

    void constructSegmentTree() {

        /*
        Segment tree size ≈ 4*N
        enough for safe allocation.
        */
        segmentTree.resize(4 * n, 0);
    }

    void updateSegTree(int idx, int val, int i, int l, int r) {

        /*
        Point Update:

        Store gap value at position idx.
        */

        // Leaf node reached
        if(l == r) {
            segmentTree[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        // Go left child
        if(idx <= mid) {
            updateSegTree(idx, val, 2 * i + 1, l, mid);
        }

        // Go right child
        else {
            updateSegTree(idx, val, 2 * i + 2, mid + 1, r);
        }

        // Store maximum gap in current range
        segmentTree[i] =
            max(segmentTree[2 * i + 1],
                segmentTree[2 * i + 2]);
    }

    int querySegTree(int start,
                     int end,
                     int i,
                     int l,
                     int r) {

        /*
        Range Maximum Query:
        Find maximum gap in [start,end]
        */

        // No overlap
        if(l > end || r < start) {
            return 0;
        }

        // Complete overlap
        if(l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;

        // Partial overlap
        return max(
            querySegTree(start, end, 2 * i + 1, l, mid),
            querySegTree(start, end, 2 * i + 2, mid + 1, r)
        );
    }

    vector<bool> getResults(vector<vector<int>>& queries) {

        // Build empty segment tree
        constructSegmentTree();

        /*
        Set stores obstacle positions.

        Initially obstacle at 0.
        */
        set<int> st;
        st.insert(0);

        vector<bool> result;

        for(auto& query : queries) {

            /*
            Type 1:
            Insert obstacle at x
            */
            if(query[0] == 1) {

                int x = query[1];

                /*
                Find nearest obstacle on right.
                */
                auto it = st.upper_bound(x);

                int nxt =
                    (it != st.end()) ? *it : -1;

                /*
                Previous obstacle.
                */
                int pre = *prev(it);

                /*
                New gap formed:

                pre ---- x

                Gap = x-pre
                */
                updateSegTree(
                    x,
                    x - pre,
                    0,
                    0,
                    n - 1
                );

                /*
                Existing gap breaks:

                pre ----- nxt

                becomes

                pre --- x --- nxt

                So update nxt gap too.
                */
                if(nxt != -1) {

                    updateSegTree(
                        nxt,
                        nxt - x,
                        0,
                        0,
                        n - 1
                    );
                }

                st.insert(x);
            }

            /*
            Type 2:
            Check if block of size sz
            can fit before x.
            */
            else {

                int x = query[1];
                int sz = query[2];

                auto it = st.upper_bound(x);

                /*
                Last obstacle <= x
                */
                int pre = *prev(it);

                /*
                Maximum complete gap
                ending before pre.
                */
                int maxGap =
                    querySegTree(
                        0,
                        pre,
                        0,
                        0,
                        n - 1
                    );

                /*
                Also consider current partial gap:

                pre ----- x
                */
                int best =
                    max(maxGap, x - pre);

                result.push_back(best >= sz);
            }
        }

        return result;
    }
};

/*
---------------- QUICK INTUITION ----------------

Obstacle positions divide line into gaps.

Example:

0 ----- 5 ----- 12 ----- 20

Gaps:
5
7
8

Segment Tree stores:
gap ending at obstacle position.

Example:
pos 5  -> gap 5
pos 12 -> gap 7
pos 20 -> gap 8

------------------------------------------------

Type 1 Query:

Insert obstacle.

Old gap:
pre ------- nxt

New gaps:
pre --- x --- nxt

Update segment tree.

------------------------------------------------

Type 2 Query:

Need block size = sz.

Find largest available gap
before position x.

If largest gap >= sz
=> true

Else false.

------------------------------------------------

Why Segment Tree?

Need:
1. Update gaps quickly
2. Query maximum gap quickly

Segment Tree:
Update -> O(log N)
Max Query -> O(log N)

------------------------------------------------

TC:

Type 1:
set + segment tree
O(log N)

Type 2:
set + query
O(log N)

Overall:
O(Q log N)

------------------------------------------------

SC:

Segment Tree -> O(N)
Set -> O(Q)

Overall:
O(N + Q)

------------------------------------------------

Pattern:

Segment Tree
Ordered Set
Range Maximum Query
Line Sweep / Interval Maintenance
*/