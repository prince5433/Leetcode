class Solution {
public:
    int largestInteger(int n, int s) {

        if (s > 9 * n) return -1;
        if(s==0) return 0;

        int maxi = -1;

        for (int i = 0; i <= 100000; i++) {

            int x = i;       // original number ko preserve karo
            int ds = 0;
            int nod = 0;

            if (x == 0) {
                nod = 1;
            }

            while (x > 0) {
                nod++;
                ds += x % 10;
                x /= 10;
            }

            if (ds == s && nod == n) {
                maxi = i;    // original number store karo
            }
        }

        return maxi;
    }
};