class Solution {
public:
    bool doesAliceWin(string s) {
        // Check each character in the string
        for (char c : s) {
            // If any vowel is found
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                return true; // Alice can win
            }
        }
        // No vowel found
        return false; // Alice cannot win
    }
};
