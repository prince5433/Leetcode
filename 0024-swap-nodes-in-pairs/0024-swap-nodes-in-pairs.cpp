
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Agar list empty hai ya sirf ek node hai,
        // toh swap karne ke liye pair available nahi hai.
        if(head ==NULL||head->next==NULL) return head;

        // First aur second current pair ke nodes hain.
        ListNode* first=head;
        ListNode* second=head->next;

        // Pehle remaining list ko recursively swap kar rahe hain.
        // Second node ke baad wali list ka swapped head first ke next se connect hoga.
        first->next=swapPairs(second->next);

        // Ab second ko first se connect karke current pair reverse kar rahe hain.
        // Pehle first -> second tha, ab second -> first ho jayega.
        second->next=first;

        // Current pair ka new head second hai, isliye ise return karenge.
        return second;
    }
};
