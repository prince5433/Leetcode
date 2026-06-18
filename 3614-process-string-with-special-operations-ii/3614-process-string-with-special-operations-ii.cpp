class Solution {
public:
    char processStr(string s, long long k) {

        /*
        Intuition:

        Final string bahut badi ho sakti hai
        because of '#'.

        So actual string build nahi karenge.

        Sirf final length track karenge
        and then reverse simulation karenge.
        */

        long long l = 0;

        /*
        Pass 1:

        Find final length after
        all operations.
        */
        for (char& ch : s) {

            // Delete last character
            if (ch == '*') {

                if (l > 0)
                    l--;
            }

            // Duplicate string
            else if (ch == '#') {

                /*
                Length doubles.

                Example:

                abc
                ->
                abcabc

                3 -> 6
                */
                l *= 2;
            }

            // Reverse string
            else if (ch == '%') {

                /*
                Reverse changes order
                but not length.
                */
            }

            // Normal character
            else {

                l++;
            }
        }

        /*
        kth index doesn't exist.
        */
        if (k >= l)
            return '.';

        /*
        Pass 2:

        Walk backwards.

        Convert current k
        into previous state k.
        */
        for (int i = s.size() - 1; i >= 0; i--) {

            /*
            Reverse operation:

            Forward:
            length decreases by 1

            Reverse:
            length increases by 1
            */
            if (s[i] == '*') {

                l++;
            }

            /*
            Reverse of duplication.

            Forward:

            A -> AA

            Length:
            l -> 2l

            Backward:

            2l -> l

            If k lies in second half,
            map it to first half.
            */
            else if (s[i] == '#') {

                l /= 2;

                if (k >= l)
                    k -= l;
            }

            /*
            Reverse operation.

            Example:

            abc

            reverse

            cba

            Index mapping:

            k -> l-k-1
            */
            else if (s[i] == '%') {

                k = l - k - 1;
            }

            /*
            Normal character insertion.

            Forward:

            append character

            Backward:

            remove last character.
            */
            else {

                l--;

                /*
                If k points exactly
                to this newly added char,
                answer found.
                */
                if (k == l)
                    return s[i];
            }
        }

        return '.';
    }
};

/*
---------------- QUICK INTUITION ----------------

Naive Approach:

Build final string.

Problem:

'#' doubles string.

Length can become huge.

------------------------------------------------

Key Idea:

Need only kth character.

Not entire string.

------------------------------------------------

Step 1:

Compute final length.

Example:

"a#b"

a

length = 1

#

length = 2

b

length = 3

------------------------------------------------

Step 2:

Move backwards.

Ask:

Current kth character
came from where?

------------------------------------------------

Reverse Mapping Rules

1) '#'

Forward:

ABC -> ABCABC

If k in second half

map:

k -= length

------------------------------------------------

2) '%'

Forward:

ABCDE

↓

EDCBA

Index mapping:

k = l-k-1

------------------------------------------------

3) Normal Character

Forward:

append char

Backward:

remove last char

If k equals last index,
current character is answer.

------------------------------------------------

Example

s = "ab#"

Forward:

ab

abab

k = 3

Backward:

'#'

length = 2

k = 3 >= 2

k = 1

Now:

"ab"

index 1

Answer = 'b'

------------------------------------------------

TC:

First pass:
O(n)

Second pass:
O(n)

Total:
O(n)

------------------------------------------------

SC:

Only variables used.

O(1)

------------------------------------------------

Pattern:

Reverse Simulation
String Construction Reversal
Greedy Index Mapping
*/