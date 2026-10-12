
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        // Step 1: Linked list ki total length nikal rahe hain,
        // taaki decide kar sakein ki har part mein kitne nodes honge.
        int n=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            n++;
        }

        // Step 2: Linked list ko k parts mein divide karne ke liye
        // har part ka minimum size aur extra nodes calculate kar rahe hain.
        vector<ListNode*> ans;
        int size=n/k; // Har part mein minimum itne nodes honge.
        int rem=n%k;  // Itne extra nodes distribute karne hain.

        temp=head;
        while(temp){

            // Dummy node use kar rahe hain, taaki current part ka head
            // aur uske nodes ko easily manage kar sakein.
            ListNode* c=new ListNode(100);
            ListNode* tempC=c;

            // Normally current part mein 'size' nodes honge.
            int s=size;

            // Agar extra nodes bache hain, toh current part ko ek extra node denge.
            // Isse pehle rem parts ka size baaki parts se 1 zyada hoga.
            if(rem>0) s++;

            // Har part ko ek extra node dene ke baad remaining extras kam kar rahe hain.
            rem--;

            // Current part mein exactly s nodes attach kar rahe hain.
            for(int i=1;i<=s;i++){

                // Original linked list ka current node current part mein attach kar rahe hain.
                tempC->next=temp;

                // Original list mein aage move kar rahe hain.
                temp=temp->next;

                // Naye attached node par move kar rahe hain,
                // taaki agla node uske baad attach ho.
                tempC=tempC->next;
            }

            // IMPORTANT: Current part ko NULL par terminate karna zaroori hai.
            // Warna woh next part ke nodes se bhi connected reh sakta hai.
            tempC->next=NULL;

            // Dummy node ko answer mein nahi rakhna; actual head c->next hai.
            ans.push_back(c->next);
        }

        // Agar linked list mein k se kam nodes hain, toh kuch parts empty honge.
        // Har empty part ko NULL se represent kar rahe hain.
        if(ans.size()<k){
            int extra=k-ans.size();
            for(int i=1;i<=extra;i++){
                ans.push_back(NULL);
            }
        }

        // Saare k parts return kar rahe hain.
        return ans;
    }
};
