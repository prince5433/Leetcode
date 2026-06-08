class Solution {
public:
    // Stores all valid binary strings
    vector<string> ans;

    void solve(int idx, int n, int k, int cost, char prev, string& temp) {

        /*
        idx  = current position
        cost = current cost of string
        prev = previous character placed
        */

        // Cost limit exceeded
        if (cost > k)
            return;

        // Complete string formed
        if (idx == n) {
            ans.push_back(temp);
            return;
        }

        // ---------------- DO: Place '0' ----------------

        temp.push_back('0');

        solve(idx + 1, n, k, cost, '0', temp);

        // UNDO
        temp.pop_back();

        // ---------------- DO: Place '1' ----------------

        /*
        '11' allowed nahi hai.

        So place '1' only when
        previous character != '1'
        */
        if (prev != '1') {

            temp.push_back('1');

            /*
            Cost contribution:

            If '1' placed at index idx,
            add idx to cost.
            */
            solve(idx + 1, n, k, cost + idx, '1', temp);

            // UNDO
            temp.pop_back();
        }
    }

    vector<string> generateValidStrings(int n, int k) {

        string temp = "";

        /*
        '#' means:
        No previous character exists.
        */
        solve(0, n, k, 0, '#', temp);

        return ans;
    }
};

/*
---------------- QUICK INTUITION ----------------

At every index:

Choice 1:
Place '0'

Choice 2:
Place '1'
(only if previous char isn't '1')

------------------------------------------------

Cost Rule:

If s[i] = '1'

cost += i

Example:

"1010"

Indices:
0 1 2 3

Cost:
0 + 2 = 2

------------------------------------------------

Recursion Tree:

idx=0

        ""
       /  \
      0    1
     / \    \
   00  01   10
   ...

------------------------------------------------

DO -> EXPLORE -> UNDO

push_back()
recursive call
pop_back()

Classic Backtracking.

------------------------------------------------

TC:

Worst Case:
O(2^n * n)

n <= 12

So easily acceptable.

------------------------------------------------

SC:

Recursion stack = O(n)

Current string = O(n)

Total = O(n)

------------------------------------------------

Pattern:

Backtracking
Recursion
String Generation
Pruning
*/