class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // -------------------------------
        // STEP 1: Find length of List A
        // -------------------------------

        ListNode* tempA = headA;
        int lenA = 0;

        while(tempA != NULL) {
            lenA++;
            tempA = tempA->next;
        }


        // -------------------------------
        // STEP 2: Find length of List B
        // -------------------------------

        ListNode* tempB = headB;
        int lenB = 0;

        while(tempB != NULL) {
            lenB++;
            tempB = tempB->next;
        }


        // -------------------------------
        // STEP 3: Reset both pointers
        // -------------------------------
        // WHY?
        // Length calculate karte waqt dono pointers
        // list ke end tak pahunch gaye the.
        // Ab intersection search ke liye heads se start karna hai.

        tempA = headA;
        tempB = headB;


        // -------------------------------
        // STEP 4: Align both pointers
        // -------------------------------
        // WHY?
        // Longer list mein extra nodes ho sakte hain.
        // Pehle un extra nodes ko skip karenge,
        // taaki dono pointers intersection se equal distance
        // par aa jayein.

        if(lenA > lenB) {

            int diff = lenA - lenB;

            // A longer hai, so A ko diff steps aage karo.
            for(int i = 1; i <= diff; i++) {
                tempA = tempA->next;
            }

        }
        else {

            int diff = lenB - lenA;

            // B longer hai, so B ko diff steps aage karo.
            for(int i = 1; i <= diff; i++) {
                tempB = tempB->next;
            }
        }


        // -------------------------------
        // STEP 5: Find intersection
        // -------------------------------
        // Ab dono pointers intersection se
        // same distance par hain.
        //
        // Isliye dono ko ek-ek step move karenge.
        while(tempA != tempB) {

            tempA = tempA->next;
            tempB = tempB->next;
        }


        // -------------------------------
        // STEP 6: Return intersection
        // -------------------------------
        // Agar intersection hai:
        // tempA == tempB → wahi node return hoga.
        //
        // Agar intersection nahi hai:
        // dono NULL par pahunch jayenge,
        // aur NULL return hoga.

        return tempA;
    }
};