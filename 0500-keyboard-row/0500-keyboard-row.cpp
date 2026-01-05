class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        vector<string> ans;   // final answer store karega

        // har word ke liye
        for (string w : words) {

            int r1 = 0, r2 = 0, r3 = 0;  // flags for 3 keyboard rows

            // word ke har character ko check karo
            for (char c : w) {

                c = tolower(c);  // lowercase me convert (case issue avoid)

                // agar char row 1 me hai
                if (string("qwertyuiop").find(c) != string::npos)
                    r1 = 1;

                // agar char row 2 me hai
                else if (string("asdfghjkl").find(c) != string::npos)
                    r2 = 1;

                // warna row 3 me hoga
                else if (string("zxcvbnm").find(c) != string::npos)
                    r3 = 1;
            }

            // agar sirf ek hi row use hui hai
            if (r1 + r2 + r3 == 1)
                ans.push_back(w);   // original word add karo
        }

        return ans;   // final result
    }
};
