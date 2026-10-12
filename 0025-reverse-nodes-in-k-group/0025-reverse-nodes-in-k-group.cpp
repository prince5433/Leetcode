
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        // Pehle check karenge ki current group mein k nodes hain ya nahi.
        // Agar k nodes nahi hue, toh remaining nodes ko reverse nahi karna hai.
        ListNode* temp=head;
        int cnt=0;

        while(cnt<k){

            // Agar k nodes check karne se pehle NULL mil gaya,
            // toh current group incomplete hai; ise as-it-is return kar do.
            if(temp==NULL) return head;

            // Next node par jaakar count badha rahe hain,
            // taaki exactly k nodes available hain ya nahi pata chale.
            temp=temp->next;
            cnt++;
        }

        // Current group ko reverse karne se pehle, next group ko recursively
        // process kar rahe hain. Ye call aage ke groups ka reversed head dega.
        // Agar last group incomplete hai, toh recursion usse unchanged return karega.
        ListNode* prev=reverseKGroup(temp,k);

        // Ab temp ko current group ke first node par wapas la rahe hain,
        // kyunki upar wala temp ab k nodes aage pahunch chuka hai.
        temp=head;
        cnt=0;

        while(cnt<k){

            // Current node ka original next save karna zaroori hai,
            // warna temp->next badalne par baaki list ka connection kho sakta hai.
            ListNode* Next=temp->next;

            // Current node ko already-processed next group se connect kar rahe hain.
            // Pehli iteration mein ye connection reversed group ko aage wali list se jodega.
            temp->next=prev;

            // Current node ab reversed part ka naya head ban gaya.
            prev=temp;

            // Original next node par move kar rahe hain, jiska address Next mein saved hai.
            temp=Next;

            // Current group ke ek node ka kaam complete ho gaya.
            cnt++;
        }

        // prev ab current reversed group ka head hai, isliye ise return karenge.
        return prev;
    }
};
