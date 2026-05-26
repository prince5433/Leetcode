class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        /*
        Intuition:
        Special char = same letter
        lowercase + uppercase dono present.

        Example:
        "aaAbBc"

        a + A -> yes
        b + B -> yes
        c only lowercase -> no
        */

        vector<int> lower(26, 0), upper(26, 0);

        // Mark lowercase / uppercase presence
        for (char ch : word) {
            if (islower(ch)) {
                lower[ch - 'a'] = 1;
            } 
            else {
                upper[ch - 'A'] = 1;
            }
        }

        int cnt = 0;

        // Check common letters
        for (int i = 0; i < 26; i++) {
            if (lower[i] == 1 && upper[i] == 1)
                cnt++;
        }

        return cnt;
    }
};

/*
Quick Idea:
2 arrays:
lower[i] -> lowercase exists
upper[i] -> uppercase exists

Dono true -> special char.

TC:
O(n + 26) = O(n)

SC:
O(26 + 26) = O(1)

Pattern:
Hashing / Frequency Tracking
Character Mapping
*/