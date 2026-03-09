class Solution {
public:

    const int MOD = 1e9 + 7;

    // dp[onesLeft][zeroesLeft][lastWasOne]
    // Memoization table:
    // onesLeft   → kitne '1' abhi place karne baaki hain
    // zeroesLeft → kitne '0' abhi place karne baaki hain
    // lastWasOne → last placed element kya tha
    //               1 → last element '1'
    //               0 → last element '0'
    int dp[201][201][2];

    int solve(int onesLeft, int zeroesLeft, bool lastWasOne, int limit) {

        // Base case:
        // Agar saare 1 aur 0 use ho gaye to ek valid stable array ban gaya
        if (onesLeft == 0 && zeroesLeft == 0) 
            return 1;

        // Agar ye state pehle se compute ho chuki hai to reuse karo
        if (dp[onesLeft][zeroesLeft][lastWasOne] != -1) {
            return dp[onesLeft][zeroesLeft][lastWasOne];
        }

        int result = 0;

        /*
        INTUITION:

        Hume binary array banana hai jisme:
        - total 'one' number of 1s
        - total 'zero' number of 0s
        - kisi bhi number ka consecutive count 'limit' se zyada na ho

        Decision depend karta hai last placed element par.

        Agar last element '1' tha:
        → ab hum '0' place kar sakte hain
        → ek baar me 1 se limit tak consecutive 0 laga sakte hain

        Agar last element '0' tha:
        → ab hum '1' place kar sakte hain
        → ek baar me 1 se limit tak consecutive 1 laga sakte hain

        Isliye recursion me hum blocks me numbers place karte hain.
        */

        // Agar last element '1' tha → ab 0 lagane honge
        if (lastWasOne == true) {

            // 1 se limit tak 0s place kar sakte hain
            for (int len = 1; len <= min(zeroesLeft, limit); len++) {

                // len zeros place kar diye
                // ab remaining zeros kam ho jayenge
                result = (result +
                         solve(onesLeft, zeroesLeft - len, false, limit)) % MOD;
            }
        }

        // Agar last element '0' tha → ab 1 lagane honge
        else {

            // 1 se limit tak 1s place kar sakte hain
            for (int len = 1; len <= min(onesLeft, limit); len++) {

                // len ones place kar diye
                // ab remaining ones kam ho jayenge
                result = (result +
                         solve(onesLeft - len, zeroesLeft, true, limit)) % MOD;
            }
        }

        // Result dp table me store karte hain taaki future me same state repeat na ho
        return dp[onesLeft][zeroesLeft][lastWasOne] = result;
    }

    int numberOfStableArrays(int zero, int one, int limit) {

        // DP array initialize with -1 (means state not computed yet)
        memset(dp, -1, sizeof(dp));

        // Case 1: agar array '1' se start kare
        // lastWasOne = false pass karte hain taaki recursion pehla block '1' ka place kare
        int startWithOne = solve(one, zero, false, limit);

        // Case 2: agar array '0' se start kare
        // lastWasOne = true pass karte hain taaki recursion pehla block '0' ka place kare
        int startWithZero = solve(one, zero, true, limit);

        // Dono possibilities ka sum hi final answer hoga
        return (startWithOne + startWithZero) % MOD;
    }
};