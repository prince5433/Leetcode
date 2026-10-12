
class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* prev = head;
        int len = 2;

        while (prev->next) {
            ListNode* curr = prev->next;
            int cnt = 0;

            // Next group ki actual length count karo
            ListNode* temp = curr;
            while (cnt < len && temp) {
                cnt++;
                temp = temp->next;
            }

            // Even length hai toh group reverse karo
            if (cnt % 2 == 0) {
                ListNode* p = temp;
                ListNode* c = curr;

                for (int i = 0; i < cnt; i++) {
                    ListNode* Next = c->next;
                    c->next = p;
                    p = c;
                    c = Next;
                }

                // Previous group ko reversed group se connect karo
                prev->next = p;

                // curr ab reversed group ka last node hai
                prev = curr;
            } else {
                // Odd length hai toh group ko reverse nahi karna
                for (int i = 0; i < cnt; i++) {
                    prev = prev->next;
                }
            }

            // Agle group ki planned length 1 se badhegi
            len++;
        }

        return head;
    }
};
