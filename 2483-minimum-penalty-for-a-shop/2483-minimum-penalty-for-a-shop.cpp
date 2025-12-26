class Solution {
public:
    int bestClosingTime(string customers) {

        int n = customers.length();   // total hours (length of string)

        int pre[n+1]; // pre[i] = penalty for 'N' customers BEFORE i-th hour
        int suf[n+1]; // suf[i] = penalty for 'Y' customers FROM i-th hour to end

        // -------------------- PREFIX ARRAY --------------------
        // If shop is open before i
        // 'N' customer aaye → penalty +1
        pre[0] = 0;   // 0 hour open → no penalty

        for(int i = 0; i < n; i++){
            // agar ith hour pe customer 'N' hai
            // to open rakhne ka penalty lagega
            pre[i+1] = pre[i] + ((customers[i] == 'N') ? 1 : 0);
        }

        // -------------------- SUFFIX ARRAY --------------------
        // If shop is closed from i
        // 'Y' customer aaye → penalty +1
        suf[n] = 0;   // n ke baad koi hour nahi → no penalty

        for(int i = n-1; i >= 0; i--){
            // agar ith hour pe customer 'Y' hai
            // aur shop band hai → penalty lagega
            suf[i] = suf[i+1] + ((customers[i] == 'Y') ? 1 : 0);
        }

        // -------------------- FIND MIN PENALTY --------------------
        int minPen = n;  // max possible penalty n ho sakti hai

        for(int i = 0; i <= n; i++){
            // total penalty at hour i:
            // open before i (pre[i]) + closed after i (suf[i])
            pre[i] += suf[i];

            int pen = pre[i];
            minPen = min(minPen, pen); // minimum penalty store
        }

        // -------------------- FIRST BEST HOUR --------------------
        // pehla hour jahan minimum penalty mile wahi answer
        for(int i = 0; i <= n; i++){
            if(pre[i] == minPen)
                return i;
        }

        return n; // fallback (practically kabhi nahi aayega)
    }
};
