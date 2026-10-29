class Solution {
public:
    int calculateScore(int a, int b) {

        // __builtin_popcount(x) batata hai ki x ke binary
        // representation mein kitne bits 1 hain.
        int sba = __builtin_popcount(a);
        int sbb = __builtin_popcount(b);

        // Agar a ke set bits, b ke set bits se zyada ya equal hain,
        // toh dono set-bit counts ka product return karo.
        if (sba >= sbb) {
            return sba * sbb;
        }

        // Agar b ke set bits, a ke set bits se zyada hain,
        // toh bade count ko chhote count se divide karke return karo.
        else {
            return sbb / sba;
        }
    }
};

/*
TIME COMPLEXITY: O(1)
32-bit integer ke liye popcount constant time mein execute hota hai.

SPACE COMPLEXITY: O(1)
Sirf fixed number of integer variables use ho rahe hain.
*/