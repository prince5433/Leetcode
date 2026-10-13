
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        // First zero ko skip kar rahe hain, kyunki uske baad se
        // next zero tak ke nodes ka sum nikalna hai.
        ListNode* temp=head->next;

        // Dummy node answer list ka starting point hai.
        // Isse first node insert karna easy ho jata hai.
        ListNode* dummy=new ListNode(0);
        ListNode* td=dummy;

        // Current segment ke non-zero nodes ka sum store karega.
        int sum=0;

        while(temp){

            // Agar current node zero nahi hai, toh uski value current sum mein add karo.
            if(temp->val!=0){
                sum+=temp->val;
            }
            else{
                // Zero milne ka matlab current segment complete ho gaya.
                // Is segment ke sum se answer list mein naya node banayenge.
                ListNode* tsum=new ListNode(sum);

                // Naye sum node ko answer list ke end mein attach karo.
                td->next=tsum;

                // Tail pointer ko naye last node par move karo,
                // taaki next sum node iske baad attach ho sake.
                td=td->next;

                // Agle segment ka sum fresh start hoga.
                sum=0;
            }

            // Original linked list ke next node par move karo.
            temp=temp->next;
        }

        // Dummy node ko answer mein include nahi karna,
        // isliye uske next se actual result return kar rahe hain.
        return dummy->next;
    }
};
