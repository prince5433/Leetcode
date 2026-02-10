class Solution {
public:
    // 12 valid color combinations for one row
    vector<string> states = {
        "RGB", "RBG",
        "GRB", "GBR",
        "BRG", "BGR",
        "RGR", "RBR",
        "GRG", "GBG",
        "BRB", "BGB"
    };

    // dp[n][prev] -> number of ways for remaining n rows
    // when previous row pattern index = prev
    int dp[5001][12];

    const int MOD = 1000000007;

    // Recursive function
    int solve(int n, int prev) {

        // Base case:
        // If no rows left to fill, one valid way exists
        if (n == 0) return 1;

        // If already computed, return stored value
        if (dp[n][prev] != -1) return dp[n][prev];

        int result = 0;

        // Get the previous row pattern
        string last = states[prev];

        // Try all possible patterns for current row
        for (int curr = 0; curr < 12; curr++) {

            string now = states[curr];

            bool faulty = false;

            // Check vertical adjacency:
            // Same column in two consecutive rows
            for (int col = 0; col < 3; col++) {
                if (last[col] == now[col]) {
                    faulty = true;   // invalid configuration
                    break;
                }
            }

            // If valid, recurse for next row
            if (!faulty) {
                result = (result + solve(n - 1, curr)) % MOD;
            }
        }

        // Store and return result
        return dp[n][prev] = result;
    }

    int numOfWays(int n) {

        // Initialize dp with -1 (uncomputed)
        memset(dp, -1, sizeof(dp));

        int ans = 0;

        // Try all 12 possible patterns for the first row
        for (int i = 0; i < 12; i++) {
            ans = (ans + solve(n - 1, i)) % MOD;
        }

        return ans;
    }
};
