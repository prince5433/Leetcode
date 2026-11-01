class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // Set current window ke unique characters store karega.
        // Set mein duplicate characters allowed nahi hote.
        unordered_set<char> st;

        int n = s.size();

        // i = window ka starting index (left pointer).
        // j = window ka ending index (right pointer).
        int i = 0, j = 0;

        // Ab tak mile longest valid substring ki length.
        int maxlen = 0;

        // Right pointer ko poori string mein move karenge.
        while (j < n) {

            // CHECK DUPLICATE:
            // Agar current character s[j] already set mein hai,
            // toh current window mein duplicate aa gaya hai.
            //
            // Humein substring mein unique characters chahiye,
            // isliye left pointer ko aage move karke window shrink karenge.
            while (st.find(s[j]) != st.end()) {

                // Leftmost character ko set se remove karo,
                // kyunki ab woh current window ka part nahi rahega.
                st.erase(s[i]);

                // Window ka starting point ek step aage badhao.
                i++;
            }

            // Ab current character duplicate nahi hai,
            // toh use set mein insert kar sakte hain.
            st.insert(s[j]);

            // Current valid window [i, j] ki length calculate karo.
            // Formula: ending index - starting index + 1.
            //
            // Is length ko previous maximum se compare karke
            // longest substring ka answer update karo.
            maxlen = max(maxlen, j - i + 1);

            // Window ko right side se expand karo,
            // taaki next character bhi include kar sakein.
            j++;
        }

        // Longest substring ki maximum length return karo.
        return maxlen;
    }
};

/*
TIME COMPLEXITY: O(N) average
Har character maximum ek baar set mein insert aur
maximum ek baar erase hota hai.
unordered_set operations average O(1) hain.

SPACE COMPLEXITY: O(min(N, charset size))
Set mein maximum window ke unique characters store honge.
*/