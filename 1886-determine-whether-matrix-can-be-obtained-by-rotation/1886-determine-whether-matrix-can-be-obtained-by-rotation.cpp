class Solution {
public:

    // Function to rotate matrix by 90 degrees clockwise
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // temporary matrix to store rotated values
        vector<vector<int>> temp(n, vector<int>(n));
        
        // rotation logic
        // element at (i, j) goes to (j, n-1-i)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                temp[j][n - 1 - i] = mat[i][j];
        
        // copy rotated matrix back to original matrix
        mat = temp;
    }

    // Function to check if two matrices are equal
    bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        
        // compare each element
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(mat[i][j] != target[i][j])
                    return false;
        
        // all elements same
        return true;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        // try all 4 possible rotations
        for(int k = 0; k < 4; k++) {
            
            // check if current matrix matches target
            if(isEqual(mat, target))
                return true;
            
            // rotate matrix by 90 degree clockwise
            rotate(mat);
        }
        
        // if no rotation matches
        return false;
    }
};