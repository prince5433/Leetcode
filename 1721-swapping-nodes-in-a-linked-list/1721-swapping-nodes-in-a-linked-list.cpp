class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        // slow aur fast dono head se start kar rahe hain.
        ListNode* slow = head;
        ListNode* fast = head;


        // WHY fast ko k steps aage?
        // Isse slow aur fast ke beech k nodes ka gap banega.
        //
        // Baad mein dono ko same speed se move karenge.
        // Jab fast NULL par pahunch jayega,
        // slow k-th node from END par hoga.
        for(int i = 1; i <= k; i++) {
            fast = fast->next;
        }


        // WHY same speed?
        // Fast already k steps ahead hai.
        // Ye gap maintain rahega.
        //
        // Jab fast list ke end par pahunchta hai,
        // slow exactly k-th node from end par hota hai.
        while(fast != NULL) {

            slow = slow->next;
            fast = fast->next;
        }


        // Ab beginning se k-th node find karenge.
        ListNode* temp = head;


        // WHY k-1?
        // temp already first node (head) par hai.
        // Isliye k-th node tak pahunchne ke liye
        // sirf k-1 steps chahiye.
        for(int i = 1; i <= k - 1; i++) {
            temp = temp->next;
        }


        // temp = k-th node from beginning
        // slow = k-th node from end
        //
        // Nodes ko rearrange karne ki zarurat nahi.
        // Sirf values swap karna enough hai.
        swap(temp->val, slow->val);


        return head;
    }
};