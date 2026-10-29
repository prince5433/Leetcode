class Solution {
public:
    int minRotations(string s) {
        int ans = 0;
        int curr = 0; // Pointer initially 0 par hai

        for (char c : s) {
            int next = c - '0'; // Character ko digit banao

            int d = abs(curr - next);

            // Circular dial par shortest distance choose karo
            ans += min(d, 10 - d);

            curr = next; // Pointer ab next digit par hai
        }

        return ans;
    }
};

/*
TC: O(n)
SC: O(1)
*/