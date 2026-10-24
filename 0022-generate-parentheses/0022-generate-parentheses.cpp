
class Solution {
public:
    /*
    backtracking approach
    QUESTION: Generate all valid combinations of n pairs of parentheses.

    INTUITION:
    Har step par '(' ya ')' choose karenge.
    '(' tabhi add hoga jab open < n.
    ')' tabhi add hoga jab close < open.

    BACKTRACKING:
    1. CHOOSE: Bracket ko current string mein add karo.
    2. EXPLORE: Recursion se aage ki possibilities banao.
    3. UNDO: Bracket remove karo, taaki doosri choice try ho sake.
    */

    void generate(vector<string>& ans, string& s,
                  int open, int close, int n) {

        // BASE CASE: Saare n opening aur n closing brackets use ho gaye.
        if (open == n && close == n) {
            ans.push_back(s);
            return;
        }

        // CHOOSE + EXPLORE: Opening bracket ki limit baaki hai.
        if (open < n) {
            s.push_back('('); // CHOOSE: Opening bracket add karo.
            generate(ans, s, open + 1, close, n); // EXPLORE: Aage badho.
            s.pop_back(); // UNDO: Doosri possibility try karne ke liye.
        }

        // CHOOSE + EXPLORE: Closing tabhi valid hai jab open > close.
        if (close < open) {
            s.push_back(')'); // CHOOSE: Closing bracket add karo.
            generate(ans, s, open, close + 1, n); // EXPLORE: Aage badho.
            s.pop_back(); // UNDO: Current choice remove karo.
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";

        // Initially koi bracket use nahi hua.
        generate(ans, s, 0, 0, n);

        return ans;
    }
};

/*
TC: O(Cn * n), where Cn = (1/(n+1)) * (2n choose n).
    Cn valid combinations generate hote hain, each of length 2n.

SC: O(n) auxiliary space for recursion and current string.
    Output storage: O(Cn * n).
*/
