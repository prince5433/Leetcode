class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size();        // number of rows in matrix
        int m = matrix[0].size();     // number of columns in matrix

        // start from row 1 and column 1
        // because first row and first column have no top-left element
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){

                // compare current element with its top-left diagonal element
                if(matrix[i][j] != matrix[i-1][j-1]){
                    return false;     // if any mismatch found → not Toeplitz
                }

            }
        }

        return true;  // if all diagonal elements match → Toeplitz matrix
    }
};
