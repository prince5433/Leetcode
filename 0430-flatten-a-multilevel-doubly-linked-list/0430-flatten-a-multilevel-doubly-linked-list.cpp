
class Solution {
public:
    Node* flatten(Node* head) {
        // Temp se main linked list traverse karenge.
        Node* temp=head;

        while(temp){
            // Current node ke baad wala original node save kar rahe hain,
            // kyunki child list insert karne par temp->next change ho jayega.
            Node*a =temp->next;

            if(temp->child!=NULL){
                // Current node ki child list ka head.
                Node* c=temp->child;

                // Child pointer remove kar rahe hain, kyunki flatten hone ke baad
                // child list normal next-prev linked list ka part ban jayegi.
                temp->child=NULL;//imp

                // Child list ko recursively flatten kar rahe hain.
                // Agar child ke andar bhi child lists hain, woh bhi flatten ho jayengi.
                c=flatten(c);//recursion

                // Current node ko flattened child list ke head se connect karo.
                temp->next=c;

                // Doubly linked list hai, isliye backward connection bhi banana hai.
                c->prev=temp;//to conoect from start

                // Flattened child list ke last node tak ja rahe hain,
                // taaki uske baad original main list ko attach kar sakein.
                while(c->next){
                    c=c->next;//c is at the last node of flaaten list
                }

                // Child list ke last node ko saved main-list node se connect karo.
                c->next=a;

                // Agar original next node exist karta hai,
                // toh uska prev bhi child list ke last node par set karo.
                if(a) a->prev=c;
            }

            // Original main list mein aage badho.
            // 'a' saved original next node hai, isliye child list ke andar
            // jaane ke bajaye main list ka traversal continue hota hai.
            temp=a;//for searching new childs
        }

        // Flattened doubly linked list ka head return karo.
        return head;
    }
};
