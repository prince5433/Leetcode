class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        // Odd-position nodes ke liye dummy list.
        ListNode* lo = new ListNode(100);

        // Even-position nodes ke liye dummy list.
        ListNode* hi = new ListNode(100);

        // Dono lists ke tail pointers.
        ListNode* tempLo = lo;
        ListNode* tempHi = hi;

        // Original linked list traverse karne ke liye.
        ListNode* temp = head;

        // First node ki position 1 hoti hai, yani odd.
        int index = 1;

        while (temp != NULL) {

            // Next node save karo, taaki original list mein
            // aage move karne ka connection safe rahe.
            ListNode* nextNode = temp->next;

            if (index % 2 == 1) { // Odd position

                // Current node ko odd list ke end mein attach karo.
                tempLo->next = temp;
                tempLo = tempLo->next;

            } else {

                // Current node ko even list ke end mein attach karo.
                tempHi->next = temp;
                tempHi = tempHi->next;
            }

            // Original list ke next node par move karo.
            temp = nextNode;
            index++;
        }

        // Even list ke last node ko NULL karo,
        // taaki purana connection unwanted nodes tak na rahe.
        tempHi->next = NULL;

        // Odd list ke end ko even list ke starting node se connect karo.
        tempLo->next = hi->next;

        // Dummy node ko skip karke final list return karo.
        return lo->next;
    }
};