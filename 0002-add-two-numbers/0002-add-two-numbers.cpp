class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     ListNode* ans = new ListNode(0); // Dummy head
    ListNode* current = ans;
    int carry = 0;
    ListNode* p = l1;
    ListNode* q = l2;
    while (p || q || carry) {
        int sum = carry; // Start with carry
        if (p) {
            sum += p->val; // Add value from l1 if available
            p = p->next; // Move to the next node in l1
        }
        if (q) {
            sum += q->val; // Add value from l2 if available
            q = q->next; // Move to the next node in l2
        }
        carry = sum / 10; // Update carry for next iteration
        current->next = new ListNode(sum % 10); // Create a new node with the digit
        current = current->next; // Move to the newly created node
    }
    return ans->next;
    }
};