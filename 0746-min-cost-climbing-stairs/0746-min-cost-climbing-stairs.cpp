class Solution {
public:

    // WHY helper() banaya?
    //
    // helper(i) return karega minimum cost
    // jo index i tak pahunchne ke liye lagegi.
    //
    // Isse same subproblem baar-baar solve nahi karna padega.
    int helper(vector<int> &cost, int i, vector<int> &dp) {

        // Base Case
        //
        // Agar hum stair 0 ya stair 1 par hain,
        // to us stair ki cost hi minimum cost hogi
        // kyuki wahi se start hua hai.
        if (i == 0 || i == 1)
            return cost[i];

        // WHY DP check?
        //
        // Agar is state ka answer pehle hi calculate
        // ho chuka hai to dobara recursion chalane ki
        // zarurat nahi hai.
        if (dp[i] != -1)
            return dp[i];

        // WHY ye recurrence?
        //
        // Stair i par sirf do jagah se aa sakte hain:
        //
        // 1. i-1
        // 2. i-2
        //
        // Dono me se jis path ki cost minimum hogi,
        // usme current stair ki cost add kar denge.
        return dp[i] = cost[i] +
                       min(helper(cost, i - 1, dp),
                           helper(cost, i - 2, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        // DP array
        //
        // dp[i] = Minimum cost to reach stair i.
        //
        // Initially sab -1 hai matlab
        // abhi koi state calculate nahi hui.
        vector<int> dp(n, -1);

        // WHY min(n-1, n-2)?
        //
        // Hum last stair par nahi,
        // uske just upar (top) jaana chahte hain.
        //
        // Top par pahunchne ke liye
        // last move ya to:
        //
        // n-1 se hogi
        // ya n-2 se.
        //
        // Isliye dono ka minimum answer return karenge.
        return min(helper(cost, n - 1, dp),
                   helper(cost, n - 2, dp));
    }
};

/*
---------------- INTUITION ----------------

Har stair par khade hokar sirf do options hote hain:

1. Previous stair (i-1) se aaye.
2. Two stairs pehle (i-2) se aaye.

To har stair ka answer sirf in dono
answers par depend karta hai.

Isi wajah se ye ek Dynamic Programming problem hai.

Top-Down DP:
Question ko recursively solve karte hain,
aur memoization ki help se repeated calculations
ko avoid karte hain.

---------------- Time Complexity ----------------

Har index sirf ek baar calculate hota hai.

Total States = n

TC = O(n)

---------------- Space Complexity ----------------

DP Array = O(n)

Recursion Stack = O(n)

Overall SC = O(n)
*/