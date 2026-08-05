class Solution {
public:
    int n;

    // dp[i][j]
    //
    // Store karega:
    //
    // Subarray [i...j] se
    // current player maximum kitne stones
    // collect kar sakta hai.
    int t[501][501];

    // WHY solve()?
    //
    // solve(i,j) return karega
    // current player ka maximum score
    // jo wo subarray [i...j] se collect kar sakta hai.
    int solve(vector<int>& piles, int i, int j) {

        // Base Case
        //
        // Koi pile nahi bachi.
        if (i > j)
            return 0;

        // WHY DP check?
        //
        // Agar current state pehle hi solve
        // ho chuki hai,
        // to dobara recursion chalane ki
        // zarurat nahi hai.
        if (t[i][j] != -1)
            return t[i][j];

        // ---------------- Choice 1 ----------------
        //
        // Current player left pile leta hai.
        //
        // Ab opponent khelega.
        //
        // Opponent bhi optimally khelega
        // aur current player ke future score
        // ko minimum karne ki koshish karega.
        //
        // Opponent ke paas do choices hongi:
        //
        // 1. Left le
        //    -> solve(i+2,j)
        //
        // 2. Right le
        //    -> solve(i+1,j-1)
        //
        // Opponent minimum wala option choose karega.
        int take_i =
            piles[i] + min(solve(piles, i + 2, j), solve(piles, i + 1, j - 1));

        // ---------------- Choice 2 ----------------
        //
        // Current player right pile leta hai.
        //
        // Fir opponent ke paas bhi
        // do optimal choices hongi.
        //
        // 1. Left le
        //    -> solve(i+1,j-1)
        //
        // 2. Right le
        //    -> solve(i,j-2)
        //
        // Opponent fir se
        // current player ka future score
        // minimum karega.
        int take_j =
            piles[j] + min(solve(piles, i, j - 2), solve(piles, i + 1, j - 1));

        // Current player
        // apne liye best option choose karega.
        return t[i][j] = max(take_i, take_j);
    }

    bool stoneGame(vector<int>& piles) {

        n = piles.size();

        // DP initialize.
        memset(t, -1, sizeof(t));

        // Total stones.
        int sum = accumulate(piles.begin(), piles.end(), 0);

        // Alex ka maximum possible score.
        int alexScore = solve(piles, 0, n - 1);

        // WHY alexScore > sum/2 ?
        //
        // Agar Alex
        // total stones ka aadha se zyada
        // collect kar leta hai,
        //
        // to obvious hai
        // Lee se zyada score hoga.
        return alexScore > sum / 2;
    }
};

/*
---------------- INTUITION ----------------

Dono players

optimally play karte hain.

Har turn par
current player ke paas
2 choices hoti hain.

1.

Left pile uthao.

2.

Right pile uthao.

---------------- WHY min() ----------------

Suppose

Current player

left pile leta hai.

Ab opponent ki turn hai.

Opponent bhi smart hai.

Wo aisa move karega
jisse current player ko
future me minimum stones mile.

Isliye

min()

use hota hai.

---------------- WHY max() ----------------

Current player
apna score maximum karna chahta hai.

Left aur Right
dono choices compare karega.

Jo zyada score degi,
wo choose karega.

Isliye

max()

use hota hai.

---------------- Example ----------------

Piles

[5,3,4,5]

Alex

Left le

↓

Lee

Best move lega

↓

Alex ka future score

minimum hoga.

Isi tarah

Right choice bhi calculate hogi.

Finally

Alex larger score wali
choice choose karega.

---------------- WHY DP ----------------

State

(i,j)

multiple baar
recursion me aa sakti hai.

Memoization ki wajah se

har state
sirf ek baar solve hoti hai.

---------------- Time Complexity ----------------

Total DP States

n × n

Har state

O(1)

work karti hai.

TC = O(n²)

---------------- Space Complexity ----------------

DP Table

O(n²)

Recursion Stack

Worst Case

O(n)

Overall SC

O(n²)
*/