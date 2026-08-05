class Solution {
public:
    bool stoneGame(vector<int>& piles) {

        // WHY directly return true?
        //
        // Is question me:
        //
        // 1. Total piles hamesha even hain.
        // 2. Total stones hamesha odd hain.
        // 3. Dono players optimally khelte hain.
        //
        // Alex (first player) pehle move me hi decide
        // kar sakta hai ki use:
        //
        // - Even indexed piles leni hain
        // OR
        // - Odd indexed piles leni hain.
        //
        // Jis parity (even/odd indices) ka total sum
        // zyada hoga, Alex wahi choose karega.
        //
        // Kyuki total piles even hain,
        // Alex poore game me usi parity ki piles
        // collect kar sakta hai.
        //
        // Isliye Alex ka score hamesha
        // Lee se strictly zyada hoga.
        //
        // Hence, answer hamesha true hi rahega.
        return true;
    }
};

/*
---------------- INTUITION ----------------

Example:

Piles

[5,3,4,5]

Indices

0 1 2 3
E O E O

Even Index Sum

5 + 4 = 9

Odd Index Sum

3 + 5 = 8

Alex game start hone se pehle hi
dekh lega ki Even Sum bada hai.

To wo strategy bana lega:

"Hamesha Even indexed piles hi lunga."

Final:

Alex = 9

Lee = 8

Alex Wins.

Isi tarah har valid test case me
Alex hamesha larger parity sum
collect kar sakta hai.

---------------- Time Complexity ----------------

TC = O(1)

---------------- Space Complexity ----------------

SC = O(1)
*/