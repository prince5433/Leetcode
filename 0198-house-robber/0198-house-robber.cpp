class Solution {
public:

    // WHY helper()?
    //
    // f(i) return karega maximum money
    // jo index i se lekar last house tak rob ki ja sakti hai.
    int f(vector<int> &arr, int i, vector<int> &dp) {

        // Base Case 1
        //
        // Sirf ek hi house bacha hai.
        //
        // To usi house ko rob karenge.
        if (i == arr.size() - 1)
            return arr[i];

        // Base Case 2
        //
        // Sirf do houses bache hain.
        //
        // Dono adjacent hain,
        // isliye ek hi rob kar sakte hain.
        //
        // Isliye maximum value return karenge.
        if (i == arr.size() - 2)
            return max(arr[i], arr[i + 1]);

        // WHY DP check?
        //
        // Agar is state ka answer pehle hi
        // calculate ho chuka hai,
        // to dobara recursion chalane ki
        // zarurat nahi hai.
        if (dp[i] != -1)
            return dp[i];

        // Option 1
        //
        // Current house rob karo.
        //
        // Fir next house rob nahi kar sakte,
        // isliye i+2 par jump karenge.
        int robCurrent =
            arr[i] + f(arr, i + 2, dp);

        // Option 2
        //
        // Current house skip kar do.
        //
        // Next house se answer nikalo.
        int skipCurrent =
            f(arr, i + 1, dp);

        // Dono options me se
        // maximum profit choose karo.
        return dp[i] =
            max(robCurrent, skipCurrent);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        // WHY ye edge case?
        //
        // Agar sirf ek house hai,
        // to wahi answer hoga.
        if (n == 1)
            return nums[0];

        // dp[i]
        //
        // Maximum money
        // jo index i se end tak rob ki ja sakti hai.
        vector<int> dp(n, -1);

        // Journey first house se start hogi.
        return f(nums, 0, dp);
    }
};

/*
---------------- INTUITION ----------------

Har house par sirf 2 choices hoti hain.

Choice 1

Current house rob karo.

To next adjacent house
rob nahi kar sakte.

Isliye i+2 par jaayenge.

Choice 2

Current house skip kar do.

Aur next house se answer nikalo.

Har house par yehi decision lena hai.

Isliye recursion + DP use hoti hai.

---------------- WHY DP ----------------

Normal recursion me
same states baar-baar solve hoti hain.

Example:

f(0)

calls

f(2)

Aur

f(1)

fir dubara

f(2)

Matlab same state repeat ho rahi hai.

Memoization ki wajah se
har state sirf ek baar calculate hoti hai.

---------------- Time Complexity ----------------

Har index sirf ek baar solve hota hai.

Total States = n

TC = O(n)

---------------- Space Complexity ----------------

DP Array = O(n)

Recursion Stack = O(n)

Overall SC = O(n)
*/