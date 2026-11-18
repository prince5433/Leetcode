
class Solution {
public:
    int minChanges(string s) {

        // Minimum changes required store karenge.
        int count = 0;

        // String ko pairs mein check karna hai.
        //
        // i = 1  -> Pair (0,1)
        // i = 3  -> Pair (2,3)
        // i = 5  -> Pair (4,5)
        //
        // Isliye i ko 2 se increase kar rahe hain.
        for(int i = 1; i < s.size(); i += 2) {

            // Current pair ke dono characters compare karo.
            //
            // Beautiful binary string ke liye
            // har pair ke dono characters same hone chahiye.
            //
            // 00 -> Already beautiful, 0 changes.
            // 11 -> Already beautiful, 0 changes.
            //
            // 01 -> Ek character change karna padega.
            // 10 -> Ek character change karna padega.
            if(s[i] != s[i - 1]) {

                // Dono characters different hain,
                // toh ek change add kar do.
                count++;
            }
        }

        // Total minimum changes return karo.
        return count;
    }
};

/*
TIME COMPLEXITY:
O(n) - Har second character par ek comparison hota hai.

SPACE COMPLEXITY:
O(1) - Sirf count variable use kiya hai.
*/
