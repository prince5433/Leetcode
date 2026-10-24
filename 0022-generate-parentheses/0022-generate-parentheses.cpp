
class Solution {
public:
    /*
    //recursive approach
    QUESTION: GENERATE PARENTHESES

    Given n pairs of parentheses, generate all combinations of
    well-formed (valid) parentheses.

    Example:
    n = 2
    Output: ["(())", "()()"]

    INTUITION:
    Har step par '(' ya ')' add kar sakte hain, lekin har choice
    valid honi chahiye.

    1. Opening '(' tabhi add karenge jab open < n.
       Kyunki total n opening brackets hi allowed hain.

    2. Closing ')' tabhi add karenge jab close < open.
       Kyunki jitne opening brackets add kiye hain, unse zyada
       closing brackets kabhi nahi hone chahiye.

    Isse invalid strings generate hi nahi hongi.
    */

    void generate(vector<string>& ans, string s,
                  int open, int close, int n) {

        // BASE CASE:
        // Jab n opening aur n closing brackets use ho gaye,
        // string complete aur valid hai, toh answer mein save karo.
        if (open == n && close == n) {
            ans.push_back(s);
            return;
        }

        // CHOOSE '(':
        // Opening brackets ki limit abhi baaki hai toh '(' add karo.
        // Isse open count badhega aur next position explore hogi.
        if (open < n) {
            generate(ans, s + '(', open + 1, close, n);
        }

        // CHOOSE ')':
        // Closing tabhi add karo jab koi unmatched opening bracket ho.
        // close < open ensure karta hai ki har prefix valid rahe.
        if (close < open) {
            generate(ans, s + ')', open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        // Initially koi bracket use nahi hua, isliye dono counts 0 hain.
        generate(ans, "", 0, 0, n);

        return ans;
    }
};

/*
TC: O(4^N / sqrt(N) * N), where N = number of bracket pairs.
    Catalan number C(N) = O(4^N / N^(3/2)) valid strings hain,
    aur har string ko store karne mein O(N) time lagta hai.

SC: O(N) recursion depth, excluding output.
    Output storage: O(N * C(N)).
*/
