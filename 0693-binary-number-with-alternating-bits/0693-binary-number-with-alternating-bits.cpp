class Solution {
public:
    bool hasAlternatingBits(int n) {

        // XOR with right shifted number
        // Alternating bits number becomes all 1s after XOR
        long long x = n ^ (n >> 1);

        // Check if x is of form 111...111
        // Property: for such numbers x & (x+1) == 0
        return ((x & (x + 1)) == 0);
    }
};
