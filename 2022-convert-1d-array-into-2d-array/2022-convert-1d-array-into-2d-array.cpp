class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        // Step 1: check if it is possible to form m x n matrix
        // total elements must be equal
        if(m * n != original.size()) 
            return {};
        
        
        // Step 2: create answer matrix of size m x n
        vector<vector<int>> ans(m, vector<int>(n, -1));
        
        
        // Step 3: fill matrix using index mapping
        for(int i = 0; i < original.size(); i++){
            
            // convert 1D index to 2D row index
            int nr = i / n;     // row = index / number of columns
            
            // convert 1D index to 2D column index
            int nc = i % n;     // column = index % number of columns
            
            
            // place element in correct position
            ans[nr][nc] = original[i];
        }
        
        
        // Step 4: return constructed 2D matrix
        return ans;
    }
};
