
class Solution {
public:
    /*
    QUESTION: LETTER CASE PERMUTATION (LeetCode 784)

    Given a string containing letters and digits, generate all strings
    possible by changing each letter into lowercase or uppercase.
    Digits ko change nahi karna hai.

    Example:
    s = "a1b"

    Output:
    ["a1b", "a1B", "A1b", "A1B"]

    INTUITION:
    Har character ko ek-ek karke process karenge.

    1. Agar character alphabet hai, toh 2 choices hain:
       - Lowercase
       - Uppercase

    2. Agar character digit hai, toh sirf 1 choice hai:
       - Digit ko unchanged rakho.

    3. Har choice ke baad recursion se next character process karenge.
       Ek choice complete hone par pop_back() se us choice ko undo
       karenge, taaki doosri choice independently explore ho sake.

    Is tarah recursion saari possible combinations generate karegi.
    */

    void f(string s, int idx, string &curr, vector<string>& result) {

        // BASE CASE:
        // Jab idx == s.size(), iska matlab saare characters process
        // ho chuke hain aur curr ek complete permutation ban chuka hai.
        // Ise result mein save karke return karo.
        if (idx == s.size()) {
            result.push_back(curr);
            return;
        }

        // Current character ko process karna hai.
        char ch = s[idx];

        // Agar character alphabet hai, toh lowercase aur uppercase
        // dono possibilities explore karni hongi.
        if (isalpha(ch)) {

            // CHOICE 1: Current letter ko lowercase banao.
            // INTUITION: Is branch mein current letter lowercase rahega
            // aur recursion baaki characters ki possibilities explore karegi.
            curr.push_back(tolower(ch));

            // EXPLORE: Agle index par jao, taaki remaining characters
            // ke saare possible case combinations generate ho sakein.
            f(s, idx + 1, curr, result);

            // UNDO / BACKTRACK:
            // Lowercase branch complete ho gayi, isliye last character
            // hatao. Ab curr previous state mein aa jayega aur uppercase
            // branch ko lowercase choice se koi interference nahi hoga.
            curr.pop_back();

            // CHOICE 2: Current letter ko uppercase banao.
            // INTUITION: Same letter ki doosri possible case explore karo.
            curr.push_back(toupper(ch));

            // EXPLORE: Uppercase choice ke saath next characters process karo.
            f(s, idx + 1, curr, result);

            // UNDO: Uppercase character bhi hatao, taaki function return
            // karte waqt curr apni original state mein restore ho jaye.
            curr.pop_back();

        } else {

            // DIGIT CASE:
            // Digit ka uppercase/lowercase nahi hota, isliye branching
            // ki zaroorat nahi. Use unchanged add karke aage badho.
            curr.push_back(ch);

            // EXPLORE: Digit ke baad wale characters process karo.
            f(s, idx + 1, curr, result);

            // UNDO: Digit remove karo, taaki previous recursive call
            // ko curr ki wahi state mile jo call se pehle thi.
            curr.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        string curr;

        // INTUITION:
        // idx = 0 se first character process karenge.
        // curr initially empty hai; recursion use ek-ek character
        // add karke complete permutations mein convert karegi.
        f(s, 0, curr, result);

        // Saari valid case permutations return karo.
        return result;
    }
};

/*
TIME COMPLEXITY:
L = number of letters, N = total string length.

O(2^L * N)
Har letter ke liye 2 choices hain, isliye 2^L permutations bante hain.
Har complete permutation ko result mein copy karne mein O(N) time lagta hai.

SPACE COMPLEXITY:
O(N) auxiliary space for curr and recursion stack.
Output storage alag hai: O(2^L * N).
*/
