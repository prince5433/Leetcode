class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int n = mat.size();    // size of square matrix
        int ans = 0;           // variable to store final sum
        
        
        // traverse entire matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                
                // primary diagonal condition
                // positions: (0,0), (1,1), (2,2) ...
                if(i == j) 
                    ans += mat[i][j];
                
                
                // secondary diagonal condition
                // positions: (0,n-1), (1,n-2), (2,n-3) ...
                if(i + j == n - 1) 
                    ans += mat[i][j];
            }
        }
        
        
        // if n is odd, center element gets counted twice
        // so subtract it once
        if(n & 1){   // check odd
            ans -= mat[n/2][n/2];
        }
        
        
        return ans;
    }
};
