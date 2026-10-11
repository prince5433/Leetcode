class Solution {
public:
    // Linked list ko reverse karna.
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* Next = curr->next; // Next node save karo.
            curr->next = prev;           // Link reverse karo.
            prev = curr;                 // Prev ko aage badhao.
            curr = Next;                 // Next node par jao.
        }

        return prev; // Reversed list ka new head.
    }

    int pairSum(ListNode* head) {
        // Slow-fast pointers se middle find karo.
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // 1 step
            fast = fast->next->next;     // 2 steps
        }

        // Second half ko reverse karo.
        ListNode* second = reverseList(slow);

        ListNode* first = head;
        int ans = 0;

        // Dono halves ke corresponding nodes ka sum nikalo.
        while (second != NULL) {
            ans = max(ans, first->val + second->val);

            first = first->next;
            second = second->next;
        }

        return ans;
    }
};