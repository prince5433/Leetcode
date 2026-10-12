
class Solution {
public:
    Node* copyRandomList(Node* head) {

        // Agar original linked list empty hai, toh copy bhi empty hogi.
        if (head == NULL) return NULL;

        // STEP 1: Har original node ki ek nayi copy create karo.
        // Abhi sirf node ki value aur next connection copy kar rahe hain.
        // Random pointer ko baad mein set karenge, kyunki uske liye
        // corresponding copied nodes ka pata hona zaroori hai.

        Node* dummy = new Node(100); // Dummy node, taaki pehli copy connect karna easy ho.
        Node* tempC = dummy;         // Copied list mein nodes attach karne ke liye.
        Node* temp = head;           // Original list ko traverse karne ke liye.

        while (temp != NULL) {
            Node* a = new Node(temp->val); // Original node ki value se naya node banao.

            tempC->next = a; // Naye node ko copied list ke end mein jodo.
            tempC = tempC->next; // Tail ko naye node par move karo.

            temp = temp->next; // Original list ke next node par jao.
        }

        Node* duplicate = dummy->next;
        // Dummy ko skip karke copied list ka actual head store kiya.
        // Ab original aur copied lists alag-alag hain.

        // STEP 2: Original aur copied nodes ko alternate positions par jodo.
        // Pehle:   Original = A -> B -> C
        //          Copy     = A' -> B' -> C'
        // Baad mein: A -> A' -> B -> B' -> C -> C'
        //
        // Is arrangement ka fayda: har original node ke just baad
        // uski corresponding copy mil jayegi.

        Node* a = head;      // Original list ka current node.
        Node* b = duplicate; // Copied list ka current node.

        dummy = new Node(-1); // Combined list banane ke liye dummy node.
        Node* tempD = dummy;  // Combined list ka tail pointer.

        while (a != NULL && b != NULL) {

            // Pehle current original node ko combined list mein jodo.
            tempD->next = a;

            a = a->next;       // Original list mein aage badho.
            tempD = tempD->next; // Combined list ka tail update karo.

            // Ab us original node ki corresponding copy ko jodo.
            tempD->next = b;

            b = b->next;       // Copy list mein aage badho.
            tempD = tempD->next; // Tail ko copied node par move karo.
        }

        Node* originalHead = dummy->next;
        // Combined list ka actual head A hai, dummy nahi.
        // Ab structure hai: A -> A' -> B -> B' -> C -> C'

        // STEP 3: Har copied node ka random pointer set karo.
        // Maan lo original node A ka random pointer C par hai.
        // Toh A' ka random pointer C' par hona chahiye.
        //
        // Kyunki har original node ke just baad uski copy hai,
        // C->next se directly C' mil jayega.

        Node* t1 = originalHead; // Original node ko point karta hai.

        while (t1 != NULL) {

            Node* t2 = t1->next;
            // t1 ke just baad uski copied node hai, isliye t2 = copy.

            if (t1->random != NULL) {
                // Original node ka random jis node par point karta hai,
                // us node ke next par uski copy milti hai.
                // Isliye copied node ka random pointer set kar sakte hain.
                t2->random = t1->random->next;
            }
            // Agar original random NULL hai, toh copied node ka random
            // bhi default NULL hi rahega.

            t1 = t1->next->next;
            // Ek original aur ek copied node skip karke next original par jao.
            // Isse random pointers sirf original nodes se process honge.
        }

        // STEP 4: Interwoven list ko original aur copied lists mein separate karo.
        // Abhi: A -> A' -> B -> B' -> C -> C'
        // Chahiye:
        // Original: A -> B -> C
        // Copy:     A' -> B' -> C'
        //
        // Dono lists ke liye alag dummy nodes use karenge.

        Node* d1 = new Node(-1); // Original list ka dummy node.
        Node* d2 = new Node(-1); // Copied list ka dummy node.

        Node* t1Copy = d1; // Original list ka tail pointer.
        Node* t2Copy = d2; // Copied list ka tail pointer.
        Node* t = originalHead; // Interwoven list ka traversal pointer.

        while (t != NULL) {

            // STEP 4A: Current original node ko original list mein jodo.
            t1Copy->next = t;

            t = t->next; // Ab original node ki copy par pahunch gaye.
            t1Copy = t1Copy->next; // Original list ka tail update karo.

            // STEP 4B: Agar copied node exist karti hai, use copied list mein jodo.
            // Ye check isliye hai taaki NULL ko node ki tarah access na karein.
            if (t != NULL) {
                t2Copy->next = t;

                t = t->next; // Copy ke baad next original node par jao.
                t2Copy = t2Copy->next; // Copied list ka tail update karo.
            }
        }

        // Dono lists ke last nodes ko NULL se terminate karo.
        // Isse original aur copied lists properly separate ho jayengi.
        t1Copy->next = NULL;
        t2Copy->next = NULL;

        // Dummy nodes ko skip karke actual heads return karo.
        // Original list apni jagah rahegi aur deep copy return hogi.
        return d2->next;
    }
};
