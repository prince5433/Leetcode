class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        // top pointer at starting row of submatrix
        int top = x;
        
        // bottom pointer at ending row of submatrix
        int bottom = x + k - 1;
        
        
        // swap rows until pointers meet
        while(top < bottom){
            
            // swap only k columns of the square
            for(int col = y; col < y + k; col++){
                
                swap(grid[top][col], grid[bottom][col]);
            }
            
            // move pointers
            top++;
            bottom--;
        }
        
        return grid;
    }
};
