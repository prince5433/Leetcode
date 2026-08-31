class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        // Maximum element ka index find karo.
        //
        // max_element() maximum element ka iterator deta hai.
        // Us iterator ko nums.begin() se subtract karne par
        // us element ka index mil jata hai.
        int maxi = max_element(nums.begin(), nums.end()) - nums.begin();

        // Minimum element ka index find karo.
        int mini = min_element(nums.begin(), nums.end()) - nums.begin();


        // Dono important elements ke indices ko
        // left aur right ke naam se arrange kar rahe hain.
        //
        // left  = dono me se chhota index
        // right = dono me se bada index
        //
        // WHY?
        // Kyuki hume minimum deletions calculate karni hain
        // aur 3 possible strategies compare karni hain.
        int left = min(maxi, mini);
        int right = max(maxi, mini);


        /*
        ---------------- 3 POSSIBLE CASES ----------------

        Hume minimum aur maximum dono elements ko
        array se remove karna hai.

        Dono elements ko remove karne ke 3 main ways hain.
        */


        // CASE 1:
        //
        // Dono elements ko LEFT side se remove karo.
        //
        // left index tak ke saare elements delete honge.
        //
        // Number of deletions = left + 1
        //
        // +1 because indexing 0 se start hui hai.
        int removeFromLeft = right + 1;


        // CASE 2:
        //
        // Dono elements ko RIGHT side se remove karo.
        //
        // right index se end tak ke elements delete honge.
        //
        // Number of deletions:
        //
        // n - left
        //
        // NOTE:
        // Actually yahan dono important elements me se
        // bade index (right) ko right se remove karna hai.
        int removeFromRight = n - left;


        // CASE 3:
        //
        // Ek element ko LEFT se remove karo
        // aur doosre ko RIGHT se.
        //
        // left side se:
        // left + 1 elements
        //
        // right side se:
        // n - right elements
        //
        // Total:
        //
        // left + 1 + n - right
        int removeBothSides = left + 1 + n - right;


        // Teeno possible strategies me se
        // minimum deletions choose karo.
        return min({
            removeBothSides,
            removeFromRight,
            removeFromLeft
        });
    }
};


/*
---------------- INTUITION ----------------

Hume minimum aur maximum element
dono ko delete karna hai.

Suppose:

nums = [2, 10, 7, 1, 5, 9]

Minimum = 1
index = 3

Maximum = 10
index = 1

So:

left = 1
right = 3


Ab 3 possibilities hain:

------------------------------------------------

CASE 1: Dono LEFT se delete

10 ka index = 1

Agar left se delete karenge:

[2, 10]

2 elements delete.

But code me:

right + 1

= 3 + 1
= 4

Because dono important elements ko cover
karne ke liye larger index (right) tak delete karna padega.

------------------------------------------------

CASE 2: Dono RIGHT se delete

right = 3

Index 3 se end tak:

[1, 5, 9]

3 elements delete.

Formula:

n - right

= 6 - 3
= 3

------------------------------------------------

CASE 3: Ek LEFT + Ek RIGHT

Maximum index = 1
Minimum index = 3

Left se:

[2, 10]

2 deletions

Right se:

[1, 5, 9]

3 deletions

Total = 5

Formula:

left + 1 + n - right

= 1 + 1 + 6 - 3

= 5

------------------------------------------------

In teeno me minimum answer choose karenge.

------------------------------------------------

IMPORTANT CORRECTION IN UNDERSTANDING

Tumhare original code me:

int left = min(maxi, mini);
int right = max(maxi, mini);

Ye bahut useful hai.

Kyuki ab hume bas ye pata hai:

left  -> pehle important element ka index
right -> doosre important element ka index

Aur 3 strategies easily calculate ho jaati hain.

------------------------------------------------

WHY max_element / min_element?

max_element() maximum element ka iterator deta hai.

Example:

nums = [5, 2, 9, 1]

max_element() -> 9

Iterator - begin()

= 2

So maximum element ka index = 2.

Same logic min_element() ke liye.

------------------------------------------------

TIME COMPLEXITY

max_element() -> O(n)

min_element() -> O(n)

Baaki calculations -> O(1)

Overall:

TC = O(n)

------------------------------------------------

SPACE COMPLEXITY

Koi extra array / map / set nahi banaya.

Sirf kuch variables use kiye hain.

SC = O(1)

------------------------------------------------

PATTERN

Array

+

Minimum / Maximum Index

+

Greedy

+

Try All Possible Deletion Strategies
*/