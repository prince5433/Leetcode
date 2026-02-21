class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int n = grid.size();        // number of rows
        int m = grid[0].size();     // number of columns

        // rowcount[i] = number of 1s in ith row
        vector<int> rowcount(n, 0);
        
        // colcount[j] = number of 1s in jth column
        vector<int> colcount(m, 0);

        // result matrix
        vector<vector<int>> ans(n, vector<int>(m, 0));

        // Step 1: count number of 1s in each row and column
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) {
                    rowcount[i]++;     // increment row count
                    colcount[j]++;     // increment column count
                }
            }
        }

        // Step 2: calculate result for each cell
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                // number of 1s in row i + column j
                int ones = rowcount[i] + colcount[j];

                // number of 0s in row i + column j
                // zeros in row = total columns - ones in row
                // zeros in col = total rows - ones in col
                int zero = (m - rowcount[i]) + (n - colcount[j]);

                // final difference
                ans[i][j] = ones - zero;
            }
        }

        return ans;   // return result matrix
    }
};