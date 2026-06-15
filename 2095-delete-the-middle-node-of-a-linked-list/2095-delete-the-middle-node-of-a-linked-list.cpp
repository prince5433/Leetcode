class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        /*
        Intuition:

        Need to delete middle node.

        Best way:
        Use Slow-Fast Pointer.

        fast -> moves 2 steps
        slow -> moves 1 step

        When fast reaches end,
        slow reaches middle.
        */

        // Single node list
        if (head == NULL || head->next == NULL)
            return NULL;

        // Slow finds middle
        ListNode* slow = head;

        // Fast reaches end
        ListNode* fast = head;

        /*
        Need previous node of middle.

        Because deletion requires:

        prev->next = slow->next
        */
        ListNode* prev = NULL;

        while (fast != NULL && fast->next != NULL) {

            // Store node before slow
            prev = slow;

            // Move slow by 1
            slow = slow->next;

            // Move fast by 2
            fast = fast->next->next;
        }

        /*
        After loop:

        slow = middle node

        prev = node before middle
        */

        // Remove middle node
        prev->next = slow->next;

        return head;
    }
};

/*
---------------- QUICK INTUITION ----------------

Example:

1 -> 3 -> 4 -> 7 -> 1 -> 2 -> 6

Initially:

slow = 1
fast = 1

--------------------------------

Iteration 1

slow = 3
fast = 4

prev = 1

--------------------------------

Iteration 2

slow = 4
fast = 1

prev = 3

--------------------------------

Iteration 3

slow = 7
fast = 6

prev = 4

--------------------------------

Loop Ends

Middle = 7

Delete:

4 -> 1

Final:

1 -> 3 -> 4 -> 1 -> 2 -> 6

------------------------------------------------

Why Slow-Fast Works?

fast moves twice as fast.

So when fast travels entire list,
slow travels only half.

Hence slow reaches middle.

------------------------------------------------

TC:

Single traversal

O(n)

------------------------------------------------

SC:

Only pointers used

O(1)

------------------------------------------------

Pattern:

Linked List
Slow Fast Pointer
Middle Node
*/