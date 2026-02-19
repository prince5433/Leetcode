class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size(); // size of square matrix
        
        // traverse entire matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                
                // check if current cell is on primary diagonal or secondary diagonal
                if(i == j || i + j == n - 1){
                    
                    // diagonal elements must be non-zero
                    if(grid[i][j] == 0)
                        return false;
                }
                else{
                    
                    // non-diagonal elements must be zero
                    if(grid[i][j] != 0)
                        return false;
                }
                
            }
        }
        
        // if all conditions satisfied
        return true;
    }
};
