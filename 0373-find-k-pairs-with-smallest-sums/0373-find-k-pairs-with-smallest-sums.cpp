class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1,
                                       vector<int>& nums2,
                                       int k) {

        vector<vector<int>> ans;

        // No pairs possible
        if (nums1.empty() || nums2.empty() || k == 0)
            return ans;

        /*
        Min Heap:

        Stores:
        {
            pairSum,
            {i, j}
        }

        Smallest sum pair always on top.
        */
      priority_queue<
    pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>
> pq;

        /*
        Visited set.

        Prevents inserting same
        index pair multiple times.
        */
        set<pair<int, int>> vis;

        /*
        Start from smallest possible pair.

        nums1[0] + nums2[0]
        */
        pq.push({
            nums1[0] + nums2[0],
            {0, 0}
        });

        vis.insert({0, 0});

        while (k-- && !pq.empty()) {

            // Current smallest sum pair
            auto [sum, p] = pq.top();
            pq.pop();

            auto [i, j] = p;

            // Store actual values
            ans.push_back({
                nums1[i],
                nums2[j]
            });

            /*
            From (i,j)

            Explore:
            (i+1,j)
            (i,j+1)

            Similar to matrix BFS.
            */

            if (i + 1 < nums1.size() &&
                !vis.count({i + 1, j})) {

                vis.insert({i + 1, j});

                pq.push({
                    nums1[i + 1] + nums2[j],
                    {i + 1, j}
                });
            }

            if (j + 1 < nums2.size() &&
                !vis.count({i, j + 1})) {

                vis.insert({i, j + 1});

                pq.push({
                    nums1[i] + nums2[j + 1],
                    {i, j + 1}
                });
            }
        }

        return ans;
    }
};

/*
---------------- QUICK INTUITION ----------------

Think of a matrix:

nums1 = [1,7,11]
nums2 = [2,4,6]

Matrix of sums:

      2   4   6
1 ->  3   5   7

7 ->  9  11  13

11-> 13  15  17

Start:
(0,0) = 3

After taking it,
possible next smallest pairs:

(1,0)
(0,1)

Keep expanding smallest sum first.

------------------------------------------------

Why Min Heap?

Need k smallest pairs.

Heap always gives
current minimum sum pair.

------------------------------------------------

Why Visited Set?

Example:

(1,1)

Can come from:
(1,0)
(0,1)

Without visited,
same pair heap me multiple times aa jayega.

------------------------------------------------

TC:

Each pair inserted once.

Heap operations:
O(log K)

Total:
O(k log k)

------------------------------------------------

SC:

Heap:
O(k)

Visited:
O(k)

Total:
O(k)

------------------------------------------------

Pattern:

Min Heap
Best First Search
Matrix Traversal
K Smallest Elements
*/