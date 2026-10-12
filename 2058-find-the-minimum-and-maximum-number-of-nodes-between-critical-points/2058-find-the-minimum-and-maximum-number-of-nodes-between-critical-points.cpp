
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx=1; // Current node b ka 1-based index track kar rahe hain.
        int fidx=-1; // First critical point ka index, maximum distance ke liye.
        int sidx=-1; // Last critical point ka index, maximum distance ke liye.

        ListNode* a=head;
        ListNode* b=head->next;
        ListNode* c=head->next->next;

        // Agar list mein sirf 2 nodes hain, toh koi middle node nahi hai
        // jiske previous aur next dono nodes available hon.
        if(c==NULL) return{-1,-1};

        int mind=INT_MAX; // Ab tak ki minimum distance store karega.
        int f=-1; // Previous critical point ka index.
        int s=-1; // Current/latest critical point ka index.

        while(c){

            // b critical point tab hai jab woh dono neighbours se strictly
            // bada (local maxima) ya strictly chhota (local minima) ho.
            if(b->val> a->val && b->val> c->val || b->val< a->val && b->val< c->val){

                // First critical point ka index ek hi baar save karna hai.
                // Last critical point ka index har naye critical point par update hoga.
                if(fidx==-1) fidx=idx;
                else sidx=idx;

                // Minimum distance ke liye consecutive critical points chahiye.
                // Isliye pichhle critical point aur current point ke indices track kar rahe hain.
                f=s;
                s=idx;

                // Pehle critical point par previous point nahi hota,
                // isliye distance tabhi calculate hoga jab f valid ho.
                if(f!=-1){
                    int d=s-f;
                    mind=min(mind,d);
                }
            }

            // Teen pointers ko ek step aage move kar rahe hain,
            // taaki har middle node ko uske left aur right neighbours ke saath check kar sakein.
            a=a->next;
            b=b->next;
            c=c->next;
            idx++;
        }

        // Agar second critical point bhi nahi mila, toh total critical points 2 se kam hain.
        if(sidx==-1) return{-1,-1};

        // First aur last critical points ke beech ka distance maximum hoga.
        int maxd=sidx-fidx;

        return{mind,maxd};
    }
};
