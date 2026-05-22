class Solution {
public:

    /*
    DFS intuition:
    Har index se hum 2 jagah jump kar sakte:
    
    1) idx + arr[idx]
    2) idx - arr[idx]

    Hume check karna hai:
    Kya start index se kisi path ke through
    hum kisi aise index tak pahuch sakte hain
    jaha value == 0 ho.

    So array ko graph treat kar sakte:
    
    Index = Node
    Possible jumps = Edges

    Problem ban gaya:
    "Can we reach a node having value 0?"
    */

    bool dfs(vector<int>& arr, vector<int>& vis, int n, int idx) {

        /*
        Base Case 1:
        Out of bounds

        Agar jump array ke bahar gaya,
        invalid move.
        */
        if (idx < 0 || idx >= n)
            return false;

        /*
        Base Case 2:
        Already visited

        Why?
        Infinite cycle avoid karne ke liye.

        Example:
        2 -> 5 -> 2 -> 5 -> 2 ...
        DFS infinitely chal sakta.
        */
        if (vis[idx])
            return false;

        /*
        Base Case 3:
        Value 0 mil gayi.

        Matlab answer mil gaya.
        */
        if (arr[idx] == 0)
            return true;

        /*
        Current index visited mark.
        Taaki dubara same state na explore ho.
        */
        vis[idx] = 1;

        /*
        Main DFS logic:

        Do possible jumps:
        Right -> idx + arr[idx]
        Left  -> idx - arr[idx]

        Agar kisi bhi direction se true mil gaya,
        final answer true.

        OR short-circuit:
        First DFS true mila to second call nahi chalegi.
        */
        return dfs(arr, vis, n, idx + arr[idx]) ||
               dfs(arr, vis, n, idx - arr[idx]);
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        /*
        Visited array:
        Har index ek baar hi process hoga.

        0 = not visited
        1 = visited
        */
        vector<int> vis(n, 0);

        /*
        DFS start from given start index.
        */
        return dfs(arr, vis, n, start);
    }
};

/*
---------------- DEEP INTUITION ----------------

Example:
arr = [4,2,3,0,3,1,2]
start = 5

Start:
idx = 5
arr[5] = 1

Possible jumps:
5 + 1 = 6
5 - 1 = 4

--------------------------------
DFS(5)
--------------------------------

Go right:
idx = 6
arr[6] = 2

Possible:
6 + 2 = 8 (invalid)
6 - 2 = 4

--------------------------------
DFS(4)
--------------------------------

arr[4] = 3

Possible:
4 + 3 = 7 (invalid)
4 - 3 = 1

--------------------------------
DFS(1)
--------------------------------

arr[1] = 2

Possible:
1 + 2 = 3
1 - 2 = -1

--------------------------------
DFS(3)
--------------------------------

arr[3] = 0

FOUND → return true

Backtracking:
true -> true -> true -> true

Final Answer = true

------------------------------------------------

WHY DFS?

Har node se multiple paths.
Tree/Graph traversal jaisa pattern.

DFS recursively explore karta:
"Ek path poora dekh lo, phir dusra."

BFS bhi possible tha.

------------------------------------------------

WHY VISITED ARRAY?

Without visited:

Suppose:
2 -> 5
5 -> 2

Cycle:
2 -> 5 -> 2 -> 5 -> 2 ...

Infinite recursion.

Visited stops repeated state traversal.

------------------------------------------------

TC (Time Complexity)

Each index max once visit hota.

DFS per node = O(1)

Total:
O(n)

Best Case:
O(1)
(start pe hi 0)

Worst Case:
O(n)

------------------------------------------------

SC (Space Complexity)

1) Visited array = O(n)

2) Recursion stack worst case:
DFS chain length = n

So total:
O(n)

------------------------------------------------

Pattern / Concept

Graph Traversal
DFS
Recursion
Visited State
Backtracking
State Space Search

------------------------------------------------

Interview one-liner:

"Treat each index as a graph node and perform DFS.
From every node, try left and right jumps.
Use visited array to avoid cycles.
If any reachable node has value 0, return true."

*/