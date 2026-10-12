
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Iterative way: pointers ki help se links reverse karenge.

        ListNode* prev=NULL; // Reversed list ka head; initially koi node nahi hai.
        ListNode* curr=head; // Current node jiska link reverse karna hai.
        ListNode* Next=NULL; // Current node ka original next save karega.

        while(curr){//while(curr!=NULL)
            // Link change karne se pehle next node save karna zaroori hai,
            // warna baaki linked list ka address lose ho sakta hai.
            Next=curr->next;

            // Current node ko previous node se connect karke link reverse kar rahe hain.
            curr->next=prev;

            // Ab current node reversed part ka naya head ban gaya.
            prev=curr;

            // Original next node par move kar rahe hain, jo Next mein saved hai.
            curr=Next;
        }

        // Curr NULL ho gaya, matlab saare links reverse ho chuke hain.
        // Prev ab reversed linked list ka head hai.
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Agar left aur right same hain, toh reverse karne ke liye sirf ek node hai.
        if(left==right) return head;

        ListNode* temp=head;

        // a = left se pehle wali node
        // b = reverse hone wale segment ki first node
        // c = reverse hone wale segment ki last node
        // d = right ke baad wali node
        ListNode* a=NULL;
        ListNode* b=NULL;
        ListNode* c=NULL;
        ListNode* d=NULL;

        // Linked list ke nodes ki 1-based positions track kar rahe hain.
        int n=1;
        while(temp){
            if(n==left-1) a=temp;  // Reversed segment se pehle ki node.
            if(n==left) b=temp;    // Segment ka starting node.
            if(n==right) c=temp;   // Segment ka ending node.
            if(n==right+1) d=temp; // Segment ke baad ki node.

            temp=temp->next;
            n++;
        }

        // Agar segment se pehle node hai, toh uska link temporarily tod rahe hain,
        // taaki segment ko independently reverse kar sakein.
        if(a) a->next=NULL;

        // Segment ke last node ka link NULL kar rahe hain,
        // taaki reverseList() sirf selected segment ko reverse kare.
        c->next=NULL;

        // b se start hone wale isolated segment ko reverse karke
        // uske naye head ka address c mein store kar rahe hain.
        c=reverseList(b);

        // Agar segment se pehle node thi, toh use reversed segment ke head se jod do.
        if(a) a->next=c;

        // Original segment ka first node b reverse hone ke baad last node ban gaya.
        // Use segment ke baad wali node d se connect kar rahe hain.
        b->next=d;

        // Agar a exist karta hai, toh original head ab bhi same rahega.
        if(a) return head;

        // Agar left = 1 tha, toh reversed segment ka head hi poori list ka head hai.
        return c;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp=head;

        // Groups ki planned lengths 1, 2, 3, 4... hoti hain.
        // Pehla group length 1 ka hota hai, isliye next group ke liye gap = 1.
        int gap=1;//start 2 length se krni hai to gap 1

        while(temp && temp->next){

            // Agle group mein actual kitne nodes available hain, woh count karenge.
            // Last group planned size se chhota bhi ho sakta hai.
            int remLen=0;//last me koi node bacha to jiski length km hai ex lastnode as in que

            // Current group ke first node ko skip karke next group ke first node par ja rahe hain.
            ListNode* t=temp->next;

            // Next group ki planned length gap+1 hai.
            // List khatam hone par loop ruk jayega, isliye actual length count ho jayegi.
            for(int i=1;i<=gap+1 && t!=NULL;i++){
                t=t->next;
                remLen++;
            }

            // Agar nodes planned size se kam hain, toh actual group size remLen hoga.
            // gap ko remLen-1 set karne se neeche gap+1 actual group size represent karega.
            if(remLen < gap+1) gap=remLen-1;

            // Even-length groups ko reverse karna hai.
            // gap planned/actual group size se 1 kam hai, isliye gap odd hone par
            // group length gap+1 even hoti hai.
            if(gap%2!=0) reverseBetween(temp,2,2+gap);//taki sirf even lenght ali list rev ho

            // Agle group ki planned length ki taraf move kar rahe hain.
            gap++;//inc the size of linkedlist

            // Current group ko cross karke temp ko next group ke start par le ja rahe hain.
            for(int i=1;i<=gap && temp!=NULL ;i++){//temp ko gap times aage badhane ke liye
                temp=temp->next;
            }
        }

        // Head same rehta hai, kyunki first group mein sirf ek node hai.
        return head;
    }
};
