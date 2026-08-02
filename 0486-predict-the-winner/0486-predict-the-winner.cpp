class Solution {
public:

    // WHY solve()?
    //
    // solve(i, j) return karega
    // current player ka maximum score difference
    // jo wo subarray [i...j] se achieve kar sakta hai.
    //
    // Score Difference =
    //
    // Current Player Score
    // -
    // Opponent Score
    int solve(vector<int>& nums, int i, int j) {

        // Base Case 1
        //
        // Koi element nahi bacha.
        //
        // Score Difference = 0.
        if (i > j)
            return 0;

        // Base Case 2
        //
        // Sirf ek element bacha hai.
        //
        // Current player wahi le lega.
        //
        // Opponent ko kuch nahi milega.
        //
        // Difference = nums[i]
        if (i == j)
            return nums[i];

        // ---------------- Choice 1 ----------------
        //
        // Left element choose karo.
        //
        // Current player ko nums[i] points milenge.
        //
        // Uske baad opponent khelega.
        //
        // solve(i+1,j)
        // opponent ka best score difference return karega.
        //
        // Isliye usse subtract karenge.
        int takeLeft =
            nums[i] - solve(nums, i + 1, j);

        // ---------------- Choice 2 ----------------
        //
        // Right element choose karo.
        //
        // Same logic.
        int takeRight =
            nums[j] - solve(nums, i, j - 1);

        // Current player
        // apne liye best option choose karega.
        return max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {

        int n = nums.size();

        // WHY >= 0 ?
        //
        // solve() final score difference return karta hai.
        //
        // Difference =
        //
        // Player1 Score
        // -
        // Player2 Score
        //
        // Agar difference
        //
        // >= 0
        //
        // hai,
        //
        // to Player1
        // ya to jeet gaya,
        // ya tie kar gaya.
        //
        // Question ke according
        // tie me bhi Player1 winner maana jata hai.
        return solve(nums, 0, n - 1) >= 0;
    }
};

/*
---------------- INTUITION ----------------

Dono players
perfectly play karte hain.

Har turn par
sirf 2 choices hain.

1.

Left element lo.

2.

Right element lo.

Current player
wo choice lega
jo uska final advantage
maximum kare.

---------------- WHY Score Difference ----------------

Agar alag-alag scores maintain karenge,

to state complicated ho jayegi.

Isliye sirf

(Current Player Score
-
Opponent Score)

store karte hain.

Example

Current Player

10

Opponent

7

Difference

=

3

---------------- WHY Minus Solve()? ----------------

Suppose

Current player ne

5

choose kiya.

Ab opponent ki turn hai.

solve()

opponent ka advantage batayega.

Current player ka
actual advantage

=

5

-

Opponent Advantage

Isi wajah se

nums[i] - solve(...)

likhte hain.

---------------- Example ----------------

nums =

[1,5,2]

Player1

1

choose karta hai.

Remaining

[5,2]

Ab opponent ka best difference

solve(1,2)

return karega.

Current Difference

=

1 - solve(1,2)

Isi tarah

Right choice bhi calculate hoti hai.

Jo maximum hogi,
wo choose karenge.

---------------- Time Complexity ----------------

Current Code me

DP nahi hai.

Same states
baar-baar solve hoti hain.

TC = O(2^n)

---------------- Space Complexity ----------------

Sirf recursion stack.

Worst Case

O(n)

---------------- OPTIMIZATION ----------------

DP State

dp[i][j]

Store karega

Maximum score difference

subarray

[i...j]

ke liye.

Optimized

TC = O(n²)

SC = O(n²)
*/