class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // WHY?
        // Empty list ya single-node list mein duplicates ho hi nahi sakte.
        if(head == NULL || head->next == NULL)
            return head;

        // a = last unique node
        // b = next node jise check karna hai
        ListNode* a = head;
        ListNode* b = head->next;

        while(b != NULL) {

            // WHY inner while?
            // Jab tak b ki value a ke equal hai,
            // tab tak duplicate nodes ko skip karte raho.
            while(b != NULL && b->val == a->val) {
                b = b->next;
            }

            // Ab b ya toh NULL hai ya next unique value par hai.
            // a ko directly b se connect kar do,
            // taaki beech ke duplicate nodes list se bypass ho jaayein.
            a->next = b;

            // WHY a = b?
            // Agar b valid hai, toh ye next unique node hai.
            // Ab isi ko next comparisons ke liye a bana denge.
            a = b;

            // WHY NULL check?
            // Agar b NULL hai, list khatam ho gayi.
            // NULL par b->next access karna invalid hoga.
            if(b != NULL)
                b = b->next;
        }

        return head;
    }
};