class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        // Dummy node banaya taaki agar head hi delete ho,
        // tab bhi handling easy rahe (head change ho sakta hai)
        ListNode* temp = new ListNode(0);

        // Dummy ka next original head ko point karega
        temp->next = head;

        // prev pointer hamesha last "safe" node pe rahega (jo delete nahi hua)
        ListNode* prev = temp;

        // curr pointer list traverse karega
        ListNode* curr = head;

        // jab tak curr null nahi ho jaata, traverse karte raho
        while (curr) {

            // agar current node ka value target val ke equal hai -> remove karna hai
            if (curr->val == val) {

                // node delete karne ke liye prev->next ko curr->next se connect kar do
                prev->next = curr->next;

                // prev ko move nahi karte, kyuki prev same node pe rahega
                // (maybe next node bhi delete karni ho)
            }
            else {
                // agar delete nahi karna, prev ko aage badha do
                prev = curr;
            }

            // curr hamesha next node pe move karega
            curr = curr->next;
        }

        // dummy ke next me final head hoga
        return temp->next;
    }
};
