class Solution {
public:

    const int MOD = 1e9 + 7;

    // dp[onesLeft][zeroesLeft][lastWasOne]
    // lastWasOne = 1 → last placed element was 1
    // lastWasOne = 0 → last placed element was 0
    int dp[201][201][2];

    int solve(int onesLeft, int zeroesLeft, bool lastWasOne, int limit) {

        // Base case: agar saare 1 aur 0 use ho gaye
        if (onesLeft == 0 && zeroesLeft == 0) return 1;

        // Agar state pehle se calculate hai to reuse karo
        if (dp[onesLeft][zeroesLeft][lastWasOne] != -1) {
            return dp[onesLeft][zeroesLeft][lastWasOne];
        }

        int result = 0;

        // Agar last element 1 tha → ab 0 lagane honge
        if (lastWasOne == true) {

            // 1 se limit tak 0s place kar sakte hain
            for (int len = 1; len <= min(zeroesLeft, limit); len++) {

                result = (result + 
                         solve(onesLeft, zeroesLeft - len, false, limit)) % MOD;
            }
        }

        // Agar last element 0 tha → ab 1 lagane honge
        else {

            // 1 se limit tak 1s place kar sakte hain
            for (int len = 1; len <= min(onesLeft, limit); len++) {

                result = (result + 
                         solve(onesLeft - len, zeroesLeft, true, limit)) % MOD;
            }
        }

        // DP me store karke return
        return dp[onesLeft][zeroesLeft][lastWasOne] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        // DP array initialize with -1
        memset(dp, -1, sizeof(dp));

        // Case 1: array starts with 1
        int startWithOne = solve(one, zero, false, limit);

        // Case 2: array starts with 0
        int startWithZero = solve(one, zero, true, limit);

        // Total ways
        return (startWithOne + startWithZero) % MOD;
    }
};