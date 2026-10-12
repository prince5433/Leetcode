class Solution {
public:
    Node* copyRandomList(Node* head) {
        //step->1 create a deep copy without random poninter
        Node* dummy=new Node(100);
        Node* tempC=dummy;
        Node* temp=head;
        while(temp){
            Node* a=new Node(temp->val);
            tempC->next=a;
            tempC=tempC->next;
            temp=temp->next;
        }
        Node* duplicate=dummy->next;//copy of original
        //step 2->alternate connections
        Node* a=head;//to traverse at original ll
        Node* b=duplicate;//to traverse at copy ll
        dummy=new Node(-1);//new node dummy
        Node* tempD=dummy;//iterator of dummy
        while(a){
             tempD->next=a;
            a=a->next;
            tempD=tempD->next;
            tempD->next=b;
            b=b->next;
            tempD=tempD->next;
        }
        dummy=dummy->next;//pointing at original linked list
        //step->3 making alternate connections
        Node* t1=dummy;//t1 willtraverse in originall linked list
        while(t1){
            Node* t2=t1->next;//t2 is for duplicate linked list
            if(t1->random!=NULL) t2->random=t1->random->next;
            t1=t1->next->next;
        }
        //step-4->separting the lists
        Node* d1=new Node(-1);
        Node* d2=new Node(-1);
         t1=d1;
        Node* t2=d2;
        Node* t=dummy;//first elemnt is of original ll
        while(t){
            t1->next=t;
            t=t->next;
            t1=t1->next;
            t2->next=t;
            t=t->next;
            t2=t2->next;
        }
        t1->next=NULL;
        t2->next=NULL;
        d1=d1->next;//origoinal ll separated
        d2=d2->next;//copied list separetd from oriinal
        return d2;

    }
};