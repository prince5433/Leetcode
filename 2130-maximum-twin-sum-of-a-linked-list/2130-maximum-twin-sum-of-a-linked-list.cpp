class Solution {
public:
    int pairSum(ListNode* head) {

        /*
        Intuition:

        Twin nodes are:

        i-th node
        and
        (n-1-i)-th node

        Linked List me direct indexing
        possible nahi hoti.

        So first convert list into array.
        */

        vector<int> v;

        // Store all node values
        while (head) {

            v.push_back(head->val);

            head = head->next;
        }

        int n = v.size();

        int ans = 0;

        /*
        Check every twin pair.

        Pair:

        i
        n-1-i
        */
        for (int i = 0; i < n / 2; i++) {

            ans = max(ans, v[i] + v[n - 1 - i]);
        }

        return ans;
    }
};

/*
---------------- QUICK INTUITION ----------------

Example:

1 -> 2 -> 3 -> 4

Array:

[1,2,3,4]

Twin Pairs:

1 + 4 = 5
2 + 3 = 5

Answer = 5

------------------------------------------------

Why Convert to Array?

Linked List:

Can't directly access:

last node
2nd last node

Array gives:

O(1) indexing

So twin pair access becomes easy.

------------------------------------------------

Dry Run

head:

5 -> 4 -> 2 -> 1

v = [5,4,2,1]

i = 0

5 + 1 = 6

ans = 6

i = 1

4 + 2 = 6

ans = 6

Return 6

------------------------------------------------

TC

Traverse List:
O(n)

Twin Pair Loop:
O(n)

Total:
O(n)

------------------------------------------------

SC

Vector stores all nodes.

O(n)

------------------------------------------------

Optimization

Can be done in:

SC = O(1)

Steps:

1. Find middle
2. Reverse second half
3. Compare both halves

TC remains O(n)

------------------------------------------------

Pattern

Linked List
Array Conversion
Two Pointers
*/