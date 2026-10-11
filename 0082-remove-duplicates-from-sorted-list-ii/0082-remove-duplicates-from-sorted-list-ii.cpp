class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // Dummy node banaya, taaki head ke duplicates bhi easily remove ho sakein.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // prev last valid node ko track karega.
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != NULL) {

            // Agar current value ke multiple occurrences hain,
            // toh us value ke saare nodes skip karne hain.
            if (curr->next != NULL &&
                curr->val == curr->next->val) {

                // Duplicate value ko store karo.
                int duplicate = curr->val;

                // Jab tak same value milti rahe, aage badho.
                while (curr != NULL && curr->val == duplicate) {
                    curr = curr->next;
                }

                // Duplicate group ko result list se completely hata do.
                prev->next = curr;
            }
            else {

                // Current node unique hai, isliye prev ko aage badhao.
                prev = curr;
                curr = curr->next;
            }
        }

        // Dummy node ko skip karke actual answer return karo.
        ListNode* ans = dummy->next;
        delete dummy;

        return ans;
    }
};