
class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        // Prev previous group ke last node ko point karega.
        // Initially first group mein sirf head node hai.
        ListNode* prev = head;

        // First group ki length 1 hai, isliye next group ki planned length 2 hogi.
        int len = 2;

        // Jab tak next group ke liye koi node available hai, process karte raho.
        while (prev->next) {

            // Current group ka first node.
            ListNode* curr = prev->next;

            // Actual group length count karne ke liye counter.
            int cnt = 0;

            // Temp next group ke nodes count karega.
            ListNode* temp = curr;
            while (cnt < len && temp) {
                cnt++;           // Ek available node count ho gaya.
                temp = temp->next; // Agle node par move karo.
            }

            // Actual length even hai, toh current group ko reverse karna hai.
            if (cnt % 2 == 0) {

                // P ko group ke baad wali list se start karte hain.
                // Isse reversed group ka last node automatically next group se connect rahega.
                ListNode* p = temp;

                // C current group ke first node se reversal start karega.
                ListNode* c = curr;

                // Exactly cnt nodes ke links reverse karo.
                for (int i = 0; i < cnt; i++) {

                    // Link change karne se pehle original next node save karo,
                    // warna remaining nodes ka address lose ho sakta hai.
                    ListNode* Next = c->next;

                    // Current node ko previous node se connect karke link reverse karo.
                    c->next = p;

                    // Current node ab reversed part ka naya head ban gaya.
                    p = c;

                    // Original next node par move karo.
                    c = Next;
                }

                // P ab reversed group ka new head hai.
                // Previous group ko is new head se connect karo.
                prev->next = p;

                // Curr original first node tha; reverse hone ke baad
                // woh current group ka last node ban gaya.
                prev = curr;

            } else {

                // Actual length odd hai, isliye group ko reverse nahi karna.
                // Prev ko group ke last node tak move karo, taaki next group process ho sake.
                for (int i = 0; i < cnt; i++) {
                    prev = prev->next;
                }
            }

            // Agle group ki planned length 1 se badhao.
            // Example: 2 ke baad 3, phir 4, phir 5...
            len++;
        }

        // Head change nahi hota, kyunki first group ki length 1 hai.
        return head;
    }
};
