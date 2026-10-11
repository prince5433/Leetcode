class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        // Do dummy nodes banao:
        // low list mein x se chhoti values hongi.
        // high list mein x ke barabar ya badi values hongi.
        ListNode* low = new ListNode(0);
        ListNode* high = new ListNode(0);

        // Tail pointers maintain karenge, taaki har node O(1) mein attach ho.
        ListNode* tempLow = low;
        ListNode* tempHigh = high;

        // Original linked list ko traverse karne ke liye pointer.
        ListNode* temp = head;

        while (temp != NULL) {

            // Current node ka next save karo,
            // kyunki temp->next ko change karne par original link lose ho jayega.
            ListNode* nextNode = temp->next;

            // Current node ko original list se detach karo,
            // taaki purane links ki wajah se unwanted connections na bane.
            temp->next = NULL;

            if (temp->val < x) {

                // Value x se chhoti hai, isliye low list ke end mein attach karo.
                tempLow->next = temp;

                // Tail ko naye last node par move karo.
                tempLow = tempLow->next;

            } else {

                // Value x ke barabar ya badi hai, isliye high list mein attach karo.
                tempHigh->next = temp;

                // High list ka tail update karo.
                tempHigh = tempHigh->next;
            }

            // Original list ke next node par jao.
            // nextNode pehle save kiya tha, isliye traversal safe hai.
            temp = nextNode;
        }

        // Low list ke end ko high list ke first actual node se jodo.
        // high dummy node hai, isliye high->next use karte hain.
        tempLow->next = high->next;

        // low dummy ko skip karke final partitioned list ka head lo.
        ListNode* ans = low->next;

        // Dono dummy nodes ko free karo; actual list ke nodes safe rahenge.
        delete low;
        delete high;

        // Final list return karo: pehle < x, phir >= x.
        return ans;
    }
};