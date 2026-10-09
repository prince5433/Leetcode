class Solution {
public:

    // WHY helper function?
    // Har baar do sorted linked lists ko merge karne ka
    // same logic reuse kar sakte hain.
    ListNode* merge(ListNode* a, ListNode* b) {

        // WHY dummy node?
        // First node attach karne ke liye alag condition
        // likhne ki zarurat nahi padti.
        ListNode* c = new ListNode(100);
        ListNode* temp = c;

        // Jab tak dono lists mein nodes hain,
        // unmein se chhoti value select karo.
        while(a != NULL && b != NULL) {

            if(a->val <= b->val) {

                // A ka node chhota ya equal hai,
                // isliye use merged list mein attach karo.
                temp->next = a;
                a = a->next;
            }
            else {

                // B ka node chhota hai,
                // isliye B ka node attach karo.
                temp->next = b;
                b = b->next;
            }

            // Tail ko aage badhao, taaki next node
            // uske baad attach ho sake.
            temp = temp->next;
        }

        // Ek list khatam ho gayi.
        // Doosri list ka remaining part sorted hai,
        // isliye use directly attach kar sakte hain.
        if(a == NULL)
            temp->next = b;
        else
            temp->next = a;

        // Dummy node ko return nahi karna;
        // actual head uske next mein hai.
        return c->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& arr) {

        // Koi list hi nahi hai, toh answer NULL.
        if(arr.size() == 0)
            return NULL;

        // Jab tak multiple lists bachi hain,
        // unhe pair-by-pair merge karte raho.
        while(arr.size() > 1) {

            // First list uthao.
            ListNode* a = arr[0];
            arr.erase(arr.begin());

            // Second list uthao.
            ListNode* b = arr[0];
            arr.erase(arr.begin());

            // Dono ko merge karke ek sorted list banao.
            ListNode* c = merge(a, b);

            // Merged list ko pending lists ke saath rakh do.
            arr.push_back(c);
        }

        // Ab vector mein ek hi list bachi hai.
        return arr[0];
    }
};