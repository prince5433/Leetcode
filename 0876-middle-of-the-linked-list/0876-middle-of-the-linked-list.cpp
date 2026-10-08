class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        // WHY slow aur fast dono head se start?
        // Dono same starting point se different speed par chalenge.
        ListNode* slow = head;
        ListNode* fast = head;


        // WHY ye condition?
        // fast ko 2 steps move karna hai:
        // fast->next->next
        //
        // Isliye:
        // 1. fast NULL nahi hona chahiye
        // 2. fast->next NULL nahi hona chahiye
        while(fast != NULL && fast->next != NULL) {

            // Slow pointer 1 step move karega.
            slow = slow->next;

            // Fast pointer 2 steps move karega.
            fast = fast->next->next;
        }


        // Jab fast end par pahunch gaya,
        // slow middle node par hoga.
        return slow;
    }
};