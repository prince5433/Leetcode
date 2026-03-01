class Solution {
public:
    int minFlips(int a, int b, int c) {

        int flips = 0;

        // Loop until all numbers become 0
        while(a != 0 || b != 0 || c != 0) {

            // Extract least significant bit (LSB) of each number
            int bitA = a & 1;
            int bitB = b & 1;
            int bitC = c & 1;

            // If current bit of c is 1
            if(bitC == 1) {

                // Then (a OR b) must be 1
                // If both are 0, we need one flip
                if(bitA == 0 && bitB == 0) {
                    flips++;
                }
            }
            else {
                // If c bit is 0,
                // then both a and b bits must be 0

                // If a has 1 → flip it
                if(bitA == 1) flips++;

                // If b has 1 → flip it
                if(bitB == 1) flips++;
            }

            // Right shift to process next bit
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return flips;
    }
};