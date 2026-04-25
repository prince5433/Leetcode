class Solution {
public:
    bool hasSameDigits(string s) {
        
        // curr stores the current working string
        string curr = s;

        // Keep reducing until only 2 digits remain
        while (curr.size() != 2) {
            
            string temp = "";

            // Create next reduced string
            for (int i = 0; i < curr.size() - 1; i++) {
                
                // Convert characters to integers
                int d1 = curr[i] - '0';
                int d2 = curr[i + 1] - '0';

                // Add adjacent digits and keep only last digit
                int sum = (d1 + d2) % 10;

                // Convert back to character and append
                temp += char(sum + '0');
            }

            // Move to newly generated string
            curr = temp;
        }

        // Check whether final two digits are same
        return curr[0] == curr[1];
    }
};