class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        // WHY -1?
        // Question ke according, jin cells mein linked list ka
        // element nahi aayega, unmein -1 rehna chahiye.
        vector<vector<int>> arr(m, vector<int>(n, -1));

        // WHY 4 boundaries?
        // Ye matrix ke abhi-unfilled region ko track karti hain.
        int minr = 0, minc = 0;
        int maxr = m - 1, maxc = n - 1;

        // Linked list ka current node.
        ListNode* temp = head;

        // Jab tak unfilled region valid hai, spiral chalao.
        while(minr <= maxr && minc <= maxc) {

            // ---------------------------------
            // 1. LEFT TO RIGHT (top row)
            // ---------------------------------
            for(int j = minc; j <= maxc; j++) {

                // WHY return?
                // Agar linked list khatam ho gayi,
                // remaining matrix cells -1 hi rehne chahiye.
                if(temp == NULL) return arr;

                // Current linked-list value ko matrix mein daalo.
                arr[minr][j] = temp->val;

                // Next linked-list node par jao.
                temp = temp->next;
            }

            // Top row fill ho gayi, ab dobara use nahi karna.
            minr++;

            // WHY boundary check?
            // Agar unfilled region khatam ho gaya,
            // toh doosri directions mein same cells dobara fill ho sakte hain.
            if(minr > maxr || minc > maxc) break;


            // ---------------------------------
            // 2. TOP TO BOTTOM (right column)
            // ---------------------------------
            for(int i = minr; i <= maxr; i++) {

                if(temp == NULL) return arr;

                arr[i][maxc] = temp->val;
                temp = temp->next;
            }

            // Right column fill ho gayi.
            maxc--;

            if(minr > maxr || minc > maxc) break;


            // ---------------------------------
            // 3. RIGHT TO LEFT (bottom row)
            // ---------------------------------
            for(int j = maxc; j >= minc; j--) {

                if(temp == NULL) return arr;

                arr[maxr][j] = temp->val;
                temp = temp->next;
            }

            // Bottom row fill ho gayi.
            maxr--;

            if(minr > maxr || minc > maxc) break;


            // ---------------------------------
            // 4. BOTTOM TO TOP (left column)
            // ---------------------------------
            for(int i = maxr; i >= minr; i--) {

                if(temp == NULL) return arr;

                arr[i][minc] = temp->val;
                temp = temp->next;
            }

            // Left column fill ho gayi.
            minc++;
        }

        return arr;
    }
};