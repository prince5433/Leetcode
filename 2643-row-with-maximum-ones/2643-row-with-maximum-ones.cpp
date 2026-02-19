class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        int maxcount = 0; // store maximum number of ones
        int idx = 0;      // store index of row with maximum ones
        
        // traverse each row
        for(int i = 0; i < n; i++){
            
            int cntones = 0;
            
            // count ones in current row
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    cntones++;
                }
            }
            
            // update maxcount and index if current row has more ones
            if(cntones > maxcount){
                maxcount = cntones;
                idx = i;
            }
        }
        
        // return result
        return {idx, maxcount};
    }
};
