class Solution {
public:
    int hammingDistance(int x, int y) {

        // x ^ y → XOR operation
        // XOR result me sirf wahi bits 1 hoti hain jaha x aur y different hote hain
        // Example:
        // x = 5  → 101
        // y = 1  → 001
        // x^y    → 100

        // __builtin_popcount() counts number of set bits (1s)
        // So it counts how many bits are different

        return __builtin_popcount(x^y);
    }
};
