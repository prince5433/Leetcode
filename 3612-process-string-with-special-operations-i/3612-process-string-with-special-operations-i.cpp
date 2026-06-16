class Solution {
public:
    string processStr(string s) {

        /*
        Intuition:

        Build final string step by step.

        Every character acts like an operation:

        '*' -> remove last character
        '#' -> duplicate current string
        '%' -> reverse current string
        letter -> append normally
        */

        string result = "";

        for (auto& ch : s) {

            // Delete last character
            if (ch == '*') {

                /*
                Avoid pop_back on
                empty string.
                */
                if (result.length() > 0) {
                    result.pop_back();
                }
            }

            // Duplicate current string
            else if (ch == '#') {

                /*
                Example:

                "abc"
                ->
                "abcabc"
                */
                result += result;
            }

            // Reverse current string
            else if (ch == '%') {

                /*
                Example:

                "abcd"
                ->
                "dcba"
                */
                reverse(result.begin(), result.end());
            }

            // Normal character
            else {

                // Append character
                result.push_back(ch);
            }
        }

        return result;
    }
};

/*
---------------- QUICK INTUITION ----------------

Operations:

'*'
Delete last character

'#'
Duplicate current string

'%'
Reverse current string

------------------------------------------------

Example:

s = "ab#c*%"

Step 1:
"a"

Step 2:
"ab"

Step 3: '#'
"abab"

Step 4:
"ababc"

Step 5: '*'
"abab"

Step 6: '%'
"baba"

Answer:
"baba"

------------------------------------------------

Dry Run

s = "abc*"

result = ""

'a' -> "a"

'b' -> "ab"

'c' -> "abc"

'*' -> "ab"

Return "ab"

------------------------------------------------

TC:

Let final string length be M.

push_back:
O(1)

pop_back:
O(1)

reverse:
O(M)

duplicate:
O(M)

Worst Case:
O(M²)

(when many '#' operations occur)

------------------------------------------------

SC:

Stores final string.

O(M)

------------------------------------------------

Pattern:

String Simulation
Implementation
*/