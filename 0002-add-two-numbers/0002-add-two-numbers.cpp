class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Result list banane ke liye dummy node.
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        int carry = 0;

        // Jab tak koi list bachi hai ya carry available hai.
        while (l1 != NULL || l2 != NULL || carry != 0) {

            // Current digits aur previous carry ka sum.
            int sum = carry;

            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Current digit result mein add karo.
            temp->next = new ListNode(sum % 10);

            // Next position ke liye carry calculate karo.
            carry = sum / 10;

            // Result list ke last node par move karo.
            temp = temp->next;
        }

        // Dummy node ko skip karke result return karo.
        ListNode* ans = dummy->next;
        delete dummy;

        return ans;
    }
};