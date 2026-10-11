class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // Approach 1: Iterative
        // Har node ka next pointer reverse direction mein point karwao.

        /*
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = NULL;

        while (curr != NULL) {

            // Next node save karo, kyunki link reverse karne par
            // original next node ka connection lose ho jayega.
            Next = curr->next;

            // Current node ka link previous node ki taraf reverse karo.
            curr->next = prev;

            // Prev aur curr ko ek step aage move karo.
            prev = curr;
            curr = Next;
        }

        // Curr NULL ho gaya, aur prev last node par hai,
        // jo reversed list ka new head hai.
        return prev;
        */

        // Approach 2: Recursive

        // Base case: empty list ya single node already reversed hai.
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Baaki linked list ko reverse karo.
        // newHead reversed list ke first node ko point karega.
        ListNode* newHead = reverseList(head->next);

        // Current node ke next node ka link reverse karo.
        // Example: 1 -> 2 ko 1 <- 2 mein convert karta hai.
        head->next->next = head;

        // Purana forward link hatao, warna cycle ban sakti hai.
        head->next = NULL;

        // Reversed list ka original last node ab new head hai.
        return newHead;
    }
};