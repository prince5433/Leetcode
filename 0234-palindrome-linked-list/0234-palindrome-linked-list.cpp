class Solution {
public:

    // Iterative approach se linked list reverse karna.
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = NULL;

        while (curr != NULL) {

            // Next node save karo, kyunki link reverse karne par
            // original next node ka connection lose ho jayega.
            Next = curr->next;

            // Current node ka link previous node ki taraf reverse karo.
            curr->next = prev;

            // Dono pointers ko aage move karo.
            prev = curr;
            curr = Next;
        }

        // Prev reversed list ka new head hai.
        return prev;
    }

    bool isPalindrome(ListNode* head) {

        // Empty list ya single node wali list palindrome hoti hai.
        if (head == NULL || head->next == NULL) {
            return true;
        }

        // Slow 1 step aur fast 2 steps move karega,
        // taaki slow left middle tak pahunch sake.
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Slow left middle par hai.
        // Second half ko reverse kar do.
        ListNode* newHead = reverseList(slow->next);

        // First half aur reversed second half ke heads.
        ListNode* a = head;
        ListNode* b = newHead;

        // Second half ke sabhi nodes compare karna enough hai,
        // kyunki odd-length list mein middle node extra hota hai.
        while (b != NULL) {

            // Values different hain toh palindrome nahi hai.
            if (a->val != b->val) {
                return false;
            }

            // Dono lists mein next nodes par move karo.
            a = a->next;
            b = b->next;
        }

        // Saare corresponding elements equal hain.
        return true;
    }
};