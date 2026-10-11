class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        // Dummy node sorted list ka starting point hai.
        // Isse beginning mein node insert karna easy ho jaata hai.
        ListNode* dummy = new ListNode(0);

        // Original linked list ko traverse karenge.
        ListNode* curr = head;

        while (curr != NULL) {

            // Next node save karo, kyunki curr ko sorted list mein insert karenge.
            ListNode* nextNode = curr->next;

            // Sorted list ke starting point se correct position find karo.
            ListNode* temp = dummy;

            // Jab tak next node ki value curr se chhoti ya equal hai,
            // aage badho taaki curr correct sorted position par insert ho.
            while (temp->next != NULL &&
                   temp->next->val <= curr->val) {
                temp = temp->next;
            }

            // Curr ko temp aur temp->next ke beech insert karo.
            curr->next = temp->next;
            temp->next = curr;

            // Original list ke next node par move karo.
            curr = nextNode;
        }

        // Dummy node ko skip karke sorted list ka head return karo.
        ListNode* ans = dummy->next;
        delete dummy;

        return ans;
    }
};