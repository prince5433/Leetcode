class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        // Agar linked list khaali hai to rotate karne ka koi matlab nahi
        if(head == NULL) return NULL;

        ListNode* temp = head;
        int len = 0;

        // Step 1: Linked list ki total length nikaal rahe hain
        // Kyunki hume pata hona chahiye kitne nodes hain
        while(temp != NULL){
            len++;
            temp = temp->next;
        }

        // Agar k = 0 hai matlab rotate hi nahi karna
        if(k == 0) return head;

        // Step 2: Rotation optimize karna
        // Example: len = 5 aur k = 8
        // 8 baar rotate karna same hai 3 baar rotate karne ke
        // isliye extra full rotations hata dete hain
        k = k % len;

        // Agar k % len = 0 aa gaya means list wapas same position pe aa jayegi
        if(k == 0) return head;

        // Step 3: Last node (tail) tak jao
        // Hume last node chahiye kyunki usko first node se connect karke
        // circular linked list banayenge
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        ListNode* tail = temp;

        // Step 4: New head ke just pehle wali node tak jao
        // Right rotate by k ka matlab:
        // last k nodes front me aayenge
        // to new head hoga (len-k+1)th node
        // aur uske pehle wala node hume todna hai
        temp = head;
        for(int i = 1; i < len - k; i++){
            temp = temp->next;
        }

        // Ab temp = new head ke previous node

        // Step 5: Tail ko old head se connect kar do
        // Isse list circular ban gayi
        tail->next = head;

        // Step 6: temp ke next ko new head bana do
        // Kyunki wahi rotation ke baad sabse pehla node hoga
        head = temp->next;

        // Step 7: temp ke baad link tod do
        // Circular list ko fir se normal singly linked list banana hai
        temp->next = NULL;

        // Final rotated linked list return
        return head;
    }
};