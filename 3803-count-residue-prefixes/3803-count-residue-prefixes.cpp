class Solution {
public:
    int residuePrefixes(string s) {
        set<char> st;        // prefix ke distinct characters store karne ke liye
        int ans = 0;         // residue prefixes ka count

        for (int i = 0; i < s.size(); i++) {
            st.insert(s[i]);    // current character ko set me daala (unique only)

            // length % 3 ki max value 2 hoti hai,
            // agar distinct characters > 2 ho gaye
            // to aage koi prefix residue nahi ban sakta
            if (st.size() > 2) break;

            // agar distinct characters == prefix length % 3
            // to ye prefix residue hai
            if (st.size() == (i + 1) % 3)
                ans++;
        }
        return ans;   // total residue prefixes
    }
};
