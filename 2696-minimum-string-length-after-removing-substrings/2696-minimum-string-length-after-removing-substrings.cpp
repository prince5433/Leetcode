class Solution {
public:
    int minLength(string s) {

        stack<char> st;

        for(char c : s) {

            if(!st.empty() &&
               ((st.top() == 'A' && c == 'B') ||
                (st.top() == 'C' && c == 'D'))) {

                st.pop();   // pair remove
            }
            else {
                st.push(c); // warna push karo
            }
        }

        return st.size();
    }
};