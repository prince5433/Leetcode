class Solution {
public:
    void deleteNode(ListNode* target) {

        // WHY next node ki value copy kar rahe hain?
        // Hume previous node ka pointer nahi mila.
        // Isliye target node ko directly delete karne ke bajay
        // uske next node ki value target mein copy kar dete hain.
        //
        // Example:
        // 1 -> 2 -> 3 -> 4
        //           target
        //
        // target->val = 4
        // Result logically:
        // 1 -> 2 -> 4 -> 4
        target->val = target->next->val;


        // WHY next node ko skip kar rahe hain?
        // Ab target mein next node ki value aa chuki hai.
        // Isliye original next node ko linked list se bypass kar denge.
        //
        // target -> next node -> next next node
        //            ↓
        //       isko skip karo
        //
        // target -> next next node
        target->next = target->next->next;
    }
};