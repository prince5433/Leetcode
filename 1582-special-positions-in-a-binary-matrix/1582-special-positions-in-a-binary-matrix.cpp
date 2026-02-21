class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int n = mat.size();        // number of rows
        int m = mat[0].size();     // number of columns
        
        // rows[i] = number of 1s in ith row
        // cols[j] = number of 1s in jth column
        vector<int> rows(n, 0), cols(m, 0);
        
        // Step 1: count number of 1s in each row and column
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    rows[i]++;     // increment row count
                    cols[j]++;     // increment column count
                }
            }
        }
        
        int cnt = 0;   // to store number of special positions
        
        // Step 2: check each cell
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                // position is special if:
                // current cell is 1
                // only 1 present in that row
                // only 1 present in that column
                if(mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1){
                    cnt++;
                }
            }
        }
        
        return cnt;    // return total special positions
    }
};