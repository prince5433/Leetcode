class Solution {
public:
    ListNode* removeNodes(ListNode* head) {

        // Stack mein ListNode ke pointers store karenge,
        // taaki original linked list ke nodes ko hi reuse kar sakein.
        stack<ListNode*> st;

        ListNode* temp = head;

        // STEP 1: Linked list ko left se right traverse karo.
        while(temp) {

            // Agar current node ki value stack ke top node se greater hai,
            // toh stack ka top node remove hoga.
            // Kyunki current node uske RIGHT mein hai aur usse greater hai,
            // isliye top node final answer mein nahi reh sakta.
            while(st.size() > 0 && st.top()->val < temp->val) {
                st.pop();
            }

            // Current node ko stack mein add karo,
            // kyunki abhi tak uske right mein koi greater node process nahi hui.
            st.push(temp);

            // Next node par move karo.
            temp = temp->next;
        }

        // Dummy pointer NULL se start hoga.
        // Stack se nodes nikalte waqt unki links dobara banayenge.
        ListNode* dummy = NULL;

        // STEP 2: Stack se nodes pop karke linked list reconstruct karo.
        // Stack LIFO hai, isliye nodes reverse order mein milenge.
        while(st.size() > 0) {

            // Current node ko already reconstructed list ke aage connect karo.
            st.top()->next = dummy;

            // Ab current node reconstructed list ka head ban jayega.
            dummy = st.top();

            // Node stack se remove kar do.
            st.pop();
        }

        // Reconstructed linked list ka head return karo.
        return dummy;
    }
};