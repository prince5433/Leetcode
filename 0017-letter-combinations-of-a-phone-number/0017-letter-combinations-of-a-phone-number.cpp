
class Solution {
public:
    vector<string> result;

    /*
    QUESTION: LETTER COMBINATIONS OF A PHONE NUMBER

    Digits string di hai, jisme 2 se 9 tak ke digits hain.
    Har digit ke corresponding phone keypad letters diye hote hain.

    Example:
    digits = "23"

    2 -> "abc"
    3 -> "def"

    Output:
    ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]

    INTUITION:
    Har digit ke corresponding letters mein se ek letter choose karna hai.

    Example "23":
    - Pehle digit '2' se a, b, ya c choose hoga.
    - Phir digit '3' se d, e, ya f choose hoga.
    - Har possible combination ko result mein store karenge.

    Backtracking mein:
    push_back() = letter choose karo.
    solve()     = next digit explore karo.
    pop_back()  = letter undo karke next choice try karo.
    */

    void solve(int idx, string &digits, string &temp,
               unordered_map<char, string> &mp) {

        // BASE CASE:
        // Jab saare digits process ho jaayein, temp ek complete
        // letter combination hai, isliye ise result mein save karo.
        if (idx >= digits.length()) {
            result.push_back(temp);
            return;
        }

        // Current digit identify karo, jaise digits = "23" mein pehle '2'.
        char ch = digits[idx];

        // INTUITION:
        // Map se current digit ke saare possible letters milte hain.
        // Example: mp['2'] = "abc", toh a, b, c try karne hain.
        string str = mp[ch];

        // Current digit ke har possible letter ko choose karo.
        for (int i = 0; i < str.size(); i++) {

            // CHOOSE: Ek letter current combination mein add karo.
            temp.push_back(str[i]);

            // EXPLORE:
            // Agle digit par jao, taaki uske letters ke saath
            // current letter ki saari combinations ban sakein.
            solve(idx + 1, digits, temp, mp);

            // UNDO / BACKTRACK:
            // Current letter wali branch complete ho gayi.
            // Letter hatao, taaki isi digit ka next letter try ho sake.
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        // Empty input ke liye koi combination possible nahi.
        if (digits.size() == 0) return {};

        // INTUITION:
        // Har digit ko uske phone keypad letters se map karte hain.
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string temp = "";

        // INTUITION:
        // Index 0 se first digit ke letters choose karna start karo.
        // Recursion automatically baaki digits process karegi.
        solve(0, digits, temp, mp);

        return result;
    }
};

/*
TC: O(4^N * N), where N = digits.length().
    Maximum 4 choices per digit; har complete combination ko
    result mein copy karne mein O(N) time lagta hai.

SC: O(N) auxiliary space for recursion stack + temp.
    Output storage is additional: O(4^N * N).
*/
