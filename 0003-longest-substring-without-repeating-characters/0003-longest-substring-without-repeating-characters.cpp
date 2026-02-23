class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        
        int n = s.size();
        int i = 0, j = 0;
        int maxlen = 0;

        while(j < n) {
            // Agar character already set me hai
            while(st.find(s[j]) != st.end()) {
                st.erase(s[i]);
                i++;
            }

            // Insert current character
            st.insert(s[j]);

            // Update maximum length
            maxlen = max(maxlen, j - i + 1);

            j++;
        }

        return maxlen;
    }
};