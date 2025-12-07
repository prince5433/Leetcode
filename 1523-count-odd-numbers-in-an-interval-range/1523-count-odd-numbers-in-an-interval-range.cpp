class Solution {
public:
    int countOdds(int low, int high) {
        // total number of integers from low to high
        int n = high - low + 1;

        // if total count is even, exactly half of them are odd
        if (n % 2 == 0) {
            return n / 2;
        } 
        else {
            // if both ends are even → odd numbers are still exactly n/2
            if (low % 2 == 0 && high % 2 == 0)
                return n / 2;
            else
                // if either low or high end is odd → odd count increases by 1
                return (n / 2) + 1;
        }

        return 0; // not reached, but added for completeness
    }
};
