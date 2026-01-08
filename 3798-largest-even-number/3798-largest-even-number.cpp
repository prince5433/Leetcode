class Solution {
public:
    string largestEven(string s) {
        int n = s.size();   // length of the string

        // Traverse from right to left
        // because we want the rightmost even digit
        for(int i = n - 1; i >= 0; i--) {

            // Convert character digit to integer
            // and check if it is even
            if ((s[i] - '0') % 2 == 0) {

                // Return the prefix ending at this even digit
                // This forms the largest possible even number
                return s.substr(0, i + 1);
            }
        }

        // If no even digit is found, return empty string
        return "";
    }
};
