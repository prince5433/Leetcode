class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flips = 0; // minimum flips needed so far
        int ones = 0;  // count of '1's seen so far

        // traverse the string from left to right
        for(char c : s){
            
            // if current character is '1'
            if(c == '1'){
                ones++; // increase count of ones
            } 
            else {
                // current character is '0'
                // two choices:
                // 1. flip this '0' to '1' → flips + 1
                // 2. flip all previous '1's to '0' → ones
                // choose minimum of both
                flips = min(flips + 1, ones);
            }
        }

        // final minimum flips required
        return flips;
    }
};
