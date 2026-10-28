class Solution {
public:
    int n, m;

    // 3D DP: dp[i][j][xor]
    // Meaning: (i, j) cell par pahunchne ke baad,
    // current XOR = xor hone par minimum possible final XOR.
    vector<vector<vector<int>>> dp;

    int f(int i, int j, int curr_xor,
          vector<vector<int>>& grid) {

        // STEP 1: Current cell ki value ko XOR mein include karo.
        // XOR mein same value do baar aaye toh cancel ho jaati hai:
        // x ^ x = 0. Isliye normal addition ki tarah sum nahi karte.
        int new_xor = curr_xor ^ grid[i][j];

        // BASE CASE:
        // Agar destination (n-1, m-1) par pahunch gaye,
        // toh new_xor poore path ka final XOR hai.
        // Ab aage move karne ki zaroorat nahi.
        if (i == n - 1 && j == m - 1) {
            return new_xor;
        }

        // MEMOIZATION:
        // Check karo kya is exact state ka answer pehle calculate hua hai.
        // State mein row, column aur current XOR teeno matter karte hain.
        // Agar answer mil gaya, toh recursion dobara chalane ki zaroorat nahi.
        if (dp[i][j][new_xor] != -1) {
            return dp[i][j][new_xor];
        }

        // Initially answer ko ek large value dete hain,
        // taaki valid paths ke XOR ke saath minimum compare kar sakein.
        int res = 1e9;

        // CHOICE 1: Neeche move karo.
        // Sirf tab move possible hai jab next row grid ke andar ho.
        if (i + 1 < n) {
            // Recursive call next cell par jayegi.
            // new_xor pass karte hain taaki current path ka XOR
            // next cell tak carry forward ho.
            res = min(res, f(i + 1, j, new_xor, grid));
        }

        // CHOICE 2: Right move karo.
        // Sirf tab move possible hai jab next column grid ke andar ho.
        if (j + 1 < m) {
            // Right wale path ka final XOR calculate karo.
            // Agar yeh neeche wale path se chhota hai,
            // toh min() usse res mein rakh lega.
            res = min(res, f(i, j + 1, new_xor, grid));
        }

        // MEMOIZATION + RETURN:
        // Dono possible directions ka minimum result store karo.
        // Agli baar same (i, j, new_xor) state aayi,
        // toh stored answer directly return ho jayega.
        return dp[i][j][new_xor] = res;
    }

    int minCost(vector<vector<int>>& grid) {

        // Grid ki dimensions store karo.
        n = grid.size();
        m = grid[0].size();

        // DP table initialize karo.
        // -1 ka matlab: is state ka answer abhi calculate nahi hua.
        // 1024 XOR states assume karta hai ki XOR value 0 se 1023 tak hai.
        dp.assign(n, vector<vector<int>>(
            m, vector<int>(1024, -1)
        ));

        // Starting cell (0,0) se recursion shuru karo.
        // Initial XOR = 0, kyunki abhi koi cell process nahi hua.
        // f() sabse pehle grid[0][0] ko XOR mein include karega.
        return f(0, 0, 0, grid);
    }
};

/*
TIME COMPLEXITY:
O(n * m * 1024) states, har state mein maximum 2 transitions.
Isliye O(n * m * 1024), agar XOR ki range 0..1023 hai.

SPACE COMPLEXITY:
O(n * m * 1024) for the DP table,
plus O(n + m) recursion stack for right/down paths.
*/