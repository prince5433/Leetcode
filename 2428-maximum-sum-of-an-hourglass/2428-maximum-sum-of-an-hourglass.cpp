class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {

        // ans stores maximum hourglass sum found so far
        int ans = INT_MIN;

        int n = grid.size();
        int m = grid[0].size();

        // hourglass 3x3 area me banta hai
        // so top-left (i, j) ka range: i = 0..n-3, j = 0..m-3
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {

                // hourglass sum:
                // grid[i][j]   grid[i][j+1]   grid[i][j+2]
                //              grid[i+1][j+1]
                // grid[i+2][j] grid[i+2][j+1] grid[i+2][j+2]
                int sum = grid[i][j] + grid[i][j+1] + grid[i][j+2]
                        + grid[i+1][j+1]
                        + grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];

                // update maximum
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};
