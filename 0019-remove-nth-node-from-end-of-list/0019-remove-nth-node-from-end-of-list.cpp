class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // WHY 2 pointers?
        // Hume end se nth node ka previous node chahiye.
        // Slow aur fast ke beech fixed gap bana kar
        // hum ek hi traversal mein ye position find kar sakte hain.
        ListNode* slow = head;
        ListNode* fast = head;


        // WHY n + 1 steps?
        //
        // Hume slow ko DELETE hone wale node se
        // exactly 1 position pehle rakhna hai.
        //
        // Isliye fast ko slow se n+1 positions aage rakhte hain.
        //
        // Example:
        // 1 -> 2 -> 3 -> 4 -> 5
        // n = 2
        //
        // Target = 4
        // Slow eventually = 3
        //
        // Gap = 3 = n + 1
        for(int i = 1; i <= n + 1; i++) {

            // WHY special case?
            // Agar fast NULL ho gaya,
            // iska matlab hum HEAD ko delete karna chahte hain.
            //
            // Example:
            // 1 -> 2 -> 3
            // n = 3
            //
            // End se 3rd node = 1 (head)
            //
            // Head ko remove karne ke baad:
            // 2 -> 3
            if(fast == NULL)
                return head->next;

            fast = fast->next;
        }


        // Ab slow aur fast ko same speed se move karenge.
        //
        // Fast already n+1 steps ahead hai,
        // so ye gap maintain rahega.
        while(fast != NULL) {

            // Slow 1 step move karega.
            slow = slow->next;

            // Fast bhi 1 step move karega.
            fast = fast->next;
        }


        // Ab slow exactly delete hone wale node ke
        // previous node par hai.
        //
        // Example:
        // 1 -> 2 -> 3 -> 4 -> 5
        //          ↑    ↑
        //        slow target
        //
        // Target = 4
        // Slow = 3
        //
        // slow->next = slow->next->next
        //
        // means:
        // 3 -> 4 -> 5
        // becomes
        // 3 ------> 5
        slow->next = slow->next->next;


        return head;
    }
};