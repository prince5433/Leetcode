
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        // STEP 1: Original linked list ki copy banao,
        // abhi sirf val aur next connections copy karenge.
        Node* dummy = new Node(100);
        Node* tempC = dummy;
        Node* temp = head;

        while (temp) {
            Node* a = new Node(temp->val);

            tempC->next = a;
            tempC = tempC->next;

            temp = temp->next;
        }

        Node* duplicate = dummy->next;

        // STEP 2: Original aur copied nodes ko alternate karo.
        // Original: A -> B -> C
        // Copy:     A' -> B' -> C'
        // Combined: A -> A' -> B -> B' -> C -> C'
        Node* a = head;
        Node* b = duplicate;

        dummy = new Node(-1);
        Node* tempD = dummy;

        while (a && b) {
            // Pehle original node ko connect karo.
            tempD->next = a;
            a = a->next;
            tempD = tempD->next;

            // Ab uske corresponding copied node ko connect karo.
            tempD->next = b;
            b = b->next;
            tempD = tempD->next;
        }

        Node* originalHead = dummy->next;

        // STEP 3: Copied nodes ke random pointers set karo.
        // Har original node ke turant baad uski copy hai.
        Node* t1 = originalHead;

        while (t1) {
            Node* t2 = t1->next; // t1 ka copied node

            // Agar original ka random pointer kisi node par hai,
            // toh us node ke just baad uski copy milegi.
            if (t1->random != NULL) {
                t2->random = t1->random->next;
            }

            // Do nodes jump karke next original node par jao.
            t1 = t1->next->next;
        }

        // STEP 4: Original aur copied lists ko separate karo.
        Node* d1 = new Node(-1);
        Node* d2 = new Node(-1);

        Node* t1Copy = d1;
        Node* t2Copy = d2;
        Node* t = originalHead;

        while (t) {
            // Original node ko original list mein add karo.
            t1Copy->next = t;
            t = t->next;
            t1Copy = t1Copy->next;

            // Agar copied node exist karti hai, use copy list mein add karo.
            if (t) {
                t2Copy->next = t;
                t = t->next;
                t2Copy = t2Copy->next;
            }
        }

        // Dono lists ke ends ko NULL se terminate karo.
        t1Copy->next = NULL;
        t2Copy->next = NULL;

        // Dummy nodes hata kar actual heads return karo.
        return d2->next;
    }
};
