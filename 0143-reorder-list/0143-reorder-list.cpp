class Solution {
public:
    // Iterative approach se linked list reverse karna.
    ListNode* reverseList(ListNode* head) {

        // Previous node initially NULL hai, kyunki reversed list ka
        // first node kisi aur node ko point nahi karega.
        ListNode* prev = NULL;

        // Curr current node ko track karega.
        ListNode* curr = head;

        // Next pointer original next node ko save karega,
        // taaki link reverse karne par connection lose na ho.
        ListNode* Next = NULL;

        while (curr) {

            // Original next node save karo.
            Next = curr->next;

            // Current node ka link reverse direction mein karo.
            curr->next = prev;

            // Prev aur curr ko ek step aage move karo.
            prev = curr;
            curr = Next;
        }

        // Prev reversed linked list ka new head hai.
        return prev;
    }

    void reorderList(ListNode* head) {

        // Slow-fast pointers se linked list ka left middle find karenge.
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {

            // Slow ek step aur fast do steps move karta hai.
            slow = slow->next;
            fast = fast->next->next;
        }

        // Slow left middle par hai.
        // Middle ke baad wali list ko reverse kar do.
        ListNode* b = reverseList(slow->next);

        // A first half ke head ko point karega.
        ListNode* a = head;

        // Dono halves ko separate kar do,
        // taaki first half aur reversed second half independent hon.
        slow->next = NULL;

        // Dono lists ko merge karne ke liye dummy node banao.
        ListNode* c = new ListNode(100);
        ListNode* tempC = c;

        // First half traverse karne ke liye pointer.
        ListNode* tempA = a;

        // Reversed second half traverse karne ke liye pointer.
        ListNode* tempB = b;

        // Jab tak dono lists mein nodes available hain,
        // unke nodes ko alternate order mein attach karo.
        while (tempA && tempB) {

            // First list ka node result mein attach karo.
            tempC->next = tempA;

            // First list mein next node par move karo.
            tempA = tempA->next;

            // Result list ka tail aage badhao.
            tempC = tempC->next;

            // Second list ka node result mein attach karo.
            tempC->next = tempB;

            // Second list mein next node par move karo.
            tempB = tempB->next;

            // Result list ka tail aage badhao.
            tempC = tempC->next;
        }

        // Agar first list mein koi node bacha hai,
        // toh use result ke end mein attach kar do.
        tempC->next = tempA;

        // Dummy node skip karke reordered list ka head set karo.
        head = c->next;
    }
};