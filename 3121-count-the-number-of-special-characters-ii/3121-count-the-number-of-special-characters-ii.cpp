class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        /*
        Intuition:
        Har character ke liye 2 cheeze track kar rahe:
        1) last lowercase occurrence
        2) first uppercase occurrence

        Valid special char tab hoga jab
        saare lowercase pehle aaye ho
        => lastLower < firstUpper
        */

        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, -1);

        // Traverse string
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];

            // Update latest lowercase index
            if (islower(ch)) {
                lastLower[ch - 'a'] = i;
            } 
            else {

                /*
                Sirf first uppercase store karna hai,
                baad wale ignore.
                */
                if (firstUpper[ch - 'A'] == -1) {
                    firstUpper[ch - 'A'] = i;
                }
            }
        }

        int cnt = 0;

        // Check valid characters
        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 &&
                firstUpper[i] != -1 &&
                lastLower[i] < firstUpper[i]) {
                cnt++;
            }
        }

        return cnt;
    }
};

/*
Quick Idea:
Last lowercase < First uppercase
=> valid special char

Example:
"aaAbcBC"

a -> 1 < 2
b -> 3 < 5
c -> 4 < 6

Ans = 3

TC: O(n)
SC: O(26) = O(1)

Pattern:
Index Tracking
Character Mapping
*/