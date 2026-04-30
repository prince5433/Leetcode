class Solution {
public:
    // Recursive helper function with memoization (Top-Down DP)
    int solve(int i, int j, int cost, int n, int m, int k,
              vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        
        // ❌ Out of bounds (invalid cell)
        if (i >= n || j >= m) return INT_MIN;

        // Current cell value and cost
        int val = grid[i][j];
        int cst = (val > 0 ? 1 : 0);  // cost = 1 if cell value > 0 (1 or 2), else 0
        int new_cost = cost + cst;

        // ❌ If total cost exceeds k, this path is invalid
        if (new_cost > k) return INT_MIN;

        // ✅ If reached bottom-right cell, return its value (valid end)
        if (i == n - 1 && j == m - 1) return val;

        // \U0001f9e0 If already computed, return from dp table (memoization)
        if (dp[i][j][cost] != -1) return dp[i][j][cost];

        // Move Down and Right recursively
        int down  = solve(i + 1, j, new_cost, n, m, k, grid, dp);
        int right = solve(i, j + 1, new_cost, n, m, k, grid, dp);

        // Take maximum valid path
        int maxi = max(down, right);

        // \U0001f4dd Store and return the best possible score from this cell & cost
        return dp[i][j][cost] = val + maxi;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // 3D DP table → dp[row][col][cost] initialized to -1
        vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(m, vector<int>(k + 1, -1)));

        // Start from top-left (0,0) with 0 cost
        int result = solve(0, 0, 0, n, m, k, grid, dp);

        // If result is negative (INT_MIN), no valid path exists
        return (result < 0) ? -1 : result;
    }
};
