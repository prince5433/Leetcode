class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int n = mat.size();        // number of rows in original matrix
        int m = mat[0].size();    // number of columns in original matrix
        
        // reshape is only possible if total elements remain same
        if(n * m != r * c) 
            return mat;
        
        
        // create new matrix of size r x c
        vector<vector<int>> ans(r, vector<int>(c, -1));
        
        
        // traverse original matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                // convert 2D index to 1D index
                int idx = i * m + j;
                
                
                // convert 1D index to new 2D index
                int nr = idx / c;   // new row
                int nc = idx % c;   // new column
                
                
                // place element in new matrix
                ans[nr][nc] = mat[i][j];
            }
        }
        
        
        // return reshaped matrix
        return ans;
    }
};
