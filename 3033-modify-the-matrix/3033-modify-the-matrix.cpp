class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        
        // n = number of rows
        int n = matrix.size();
        
        // m = number of columns
        int m = matrix[0].size();
        
        
        // cols array banayenge jisme har column ka maximum store hoga
        // initially INT_MIN se initialize kiya hai taki proper max calculate ho sake
        vector<int> cols(m, INT_MIN);
        
        
        // STEP 1: har column ka maximum find karna
        for(int i = 0; i < m; i++){          // column loop
            
            for(int j = 0; j < n; j++){      // row loop
                
                // sirf valid values consider karni hain (ignore -1)
                if(matrix[j][i] != -1){
                    
                    // column i ka maximum update karo
                    cols[i] = max(cols[i], matrix[j][i]);
                }
            }
        }
        
        
        // STEP 2: matrix traverse karo aur -1 ko replace karo
        for(int i = 0; i < n; i++){          // row loop
            
            for(int j = 0; j < m; j++){      // column loop
                
                // agar element -1 hai
                if(matrix[i][j] == -1){
                    
                    // usko us column ke maximum value se replace karo
                    matrix[i][j] = cols[j];
                }
            }
        }
        
        
        // modified matrix return karo
        return matrix;
    }
};
