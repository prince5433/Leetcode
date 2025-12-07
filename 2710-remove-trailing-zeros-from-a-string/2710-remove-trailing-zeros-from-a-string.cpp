class Solution {
public:
    string removeTrailingZeros(string num) {

        // Length of the string (number)
        int n = num.size();
        
        // Variable to store the index of the last NON-zero digit
        int idx = -1;

        // Traverse from the end of the string backwards
        for (int i = n - 1; i >= 0; i--) {
            
            // As soon as we find a digit that is not '0'
            // that means trailing zeros end here
            if (num[i] != '0') {
                idx = i;
                break;
            }
        }

        // Take substring from 0 to idx (inclusive)
        // All trailing zeros are removed
        string t = num.substr(0, idx + 1);

        return t;
    }
};
