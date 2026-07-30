class Solution {
public:

    int minimumPushes(string word) {

        // Total characters in the word.
        int n = word.size();

        // Final answer.
        int ans = 0;

        // WHY loop over all characters?
        //
        // Har character ke liye
        // uske required key presses
        // answer me add karenge.
        for (int i = 0; i < n; i++) {

            // WHY (i / 8) + 1 ?
            //
            // Ek mobile keypad me
            // maximum 8 letters
            // same push count share kar sakte hain.
            //
            // First 8 letters
            // -> 1 push
            //
            // Next 8 letters
            // -> 2 pushes
            //
            // Next 8 letters
            // -> 3 pushes
            //
            // ...
            //
            // Integer division ki wajah se
            //
            // i = 0 to 7
            // i/8 = 0
            // Pushes = 1
            //
            // i = 8 to 15
            // i/8 = 1
            // Pushes = 2
            //
            // i = 16 to 23
            // i/8 = 2
            // Pushes = 3
            ans += (i / 8) + 1;
        }

        return ans;
    }
};

/*
---------------- INTUITION ----------------

Question me
letters ko keypad par
is tarah assign karna hai
ki total pushes minimum ho.

Sabse frequent letters ko
1 push wali positions milni chahiye.

Uske baad

next letters ko

2 push wali positions.

Fir

3 push wali positions.

Ek push group me
maximum 8 letters
aa sakte hain.

---------------- Example ----------------

Word Length = 10

Positions

0 1 2 3 4 5 6 7

Pushes

1 1 1 1 1 1 1 1

----------------

Positions

8 9

Pushes

2 2

Total

8 × 1

+

2 × 2

=

12

---------------- WHY Integer Division ----------------

Suppose

i = 13

13 / 8

=

1

Pushes

=

1 + 1

=

2

----------------

Suppose

i = 20

20 / 8

=

2

Pushes

=

2 + 1

=

3

Isliye

(i / 8) + 1

har character ka
correct push count de deta hai.

---------------- Time Complexity ----------------

Loop

O(n)

Overall

TC = O(n)

---------------- Space Complexity ----------------

Koi extra data structure
use nahi hua.

SC = O(1)
*/