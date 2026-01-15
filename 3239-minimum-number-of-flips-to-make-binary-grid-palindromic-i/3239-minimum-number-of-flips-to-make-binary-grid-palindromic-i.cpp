class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int rf = 0;  // flips needed to make all rows palindromic
        for(int row = 0; row < n; row++) {
            int l = 0, r = m - 1;
            while(l < r) {
                if(grid[row][l] != grid[row][r]) {
                    rf++;  // one flip fixes this mismatched pair
                }
                l++;
                r--;
            }
        }

        int cf = 0;  // flips needed to make all columns palindromic
        for(int col = 0; col < m; col++) {
            int l = 0, r = n - 1;
            while(l < r) {
                if(grid[l][col] != grid[r][col]) {
                    cf++;  // one flip fixes this mismatched pair
                }
                l++;
                r--;
            }
        }

        // choose the minimum flips between rows or columns
        return min(rf, cf);
    }
};
