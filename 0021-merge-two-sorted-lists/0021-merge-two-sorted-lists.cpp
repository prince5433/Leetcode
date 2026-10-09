class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {

        //space complexity of O(1)
        // Step 1: Dummy node create karo
        // Intuition:
        // Dummy node se head handle karna easy ho jata hai
        // (no special case for first node)
        ListNode* c = new ListNode(100);

        // temp pointer → merged list banane ke liye
        ListNode* temp = c;

        // Step 2: Dono lists compare karte hue merge karo
        while(a != NULL && b != NULL){

            // Intuition:
            // Jo chhota value hai usko pehle attach karo
            if(a->val <= b->val){
                temp->next = a;   // 'a' ko add karo
                a = a->next;      // a ko aage badhao
            }
            else{
                temp->next = b;   // 'b' ko add karo
                b = b->next;      // b ko aage badhao
            }

            // temp ko bhi aage badhao (tail maintain karne ke liye)
            temp = temp->next;
        }

        // Step 3: Jo list bachi hai usko directly attach kar do

        // Intuition:
        // Kyunki lists sorted hain, remaining part already sorted hoga
        if(a == NULL) temp->next = b;
        else temp->next = a;

        // Step 4: dummy ke next ko return karo (actual head)
        return c->next;
    }
};