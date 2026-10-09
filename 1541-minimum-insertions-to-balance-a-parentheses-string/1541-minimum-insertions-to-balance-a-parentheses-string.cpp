class Solution {
public:
    int minInsertions(string s) {

        // cnt = unmatched opening brackets '('
        // Har opening bracket ko aage '))' chahiye.
        int cnt = 0;

        int n = s.size();

        // result = ab tak kitne brackets insert kiye.
        int result = 0;

        int i = 0;

        while(i < n) {

            // CASE 1: Opening bracket '(' mila
            if(s[i] == '(') {

                // Is opening bracket ko future mein '))' chahiye.
                cnt++;

                i++;
            }

            else { // CASE 2: Closing bracket ')' mila

                // Agar koi unmatched '(' available hai,
                // toh ye ')' us opening bracket ke required pair
                // ka pehla ya doosra bracket ho sakta hai.
                if(cnt > 0) {

                    // Ek opening bracket ki requirement reduce hui.
                    cnt--;

                }
                else {

                    // Koi '(' available nahi hai.
                    // Current ')' ko match karne ke liye '(' insert karo.
                    result++;
                }

                // WHY next character check karte hain?
                // Kyunki har '(' ke liye exactly '))' chahiye.
                // Agar next character bhi ')', toh pair complete hai.
                if(i + 1 < n && s[i + 1] == ')') {

                    // Dono ')' consume kar liye.
                    i += 2;

                }
                else {

                    // Sirf ek ')' mila.
                    // Required pair '))' complete karne ke liye
                    // ek extra ')' insert karna padega.
                    result++;

                    i++;
                }
            }
        }

        // WHY cnt * 2?
        // Har unmatched '(' ko 2 closing brackets chahiye.
        // Isliye har remaining opening bracket ke liye 2 insertions.
        return result + cnt * 2;
    }
};