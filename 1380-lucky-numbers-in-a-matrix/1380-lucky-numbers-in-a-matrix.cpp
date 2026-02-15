class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        
        int n = matrix.size();        // number of rows
        int m = matrix[0].size();    // number of columns
        
        set<int> s;                  // set to store minimum of each row
        
        
        // Step 1: find minimum element of each row and insert into set
        for(int i = 0; i < n; i++){
            
            int mini = INT_MAX;      // initialize minimum for current row
            
            for(int j = 0; j < m; j++){
                mini = min(mini, matrix[i][j]);   // update row minimum
            }
            
            s.insert(mini);         // store row minimum in set
        }
        
        
        vector<int> ans;            // vector to store lucky numbers
        
        
        // Step 2: find maximum element of each column
        for(int j = 0; j < m; j++){
            
            int maxi = INT_MIN;     // initialize maximum for current column
            
            for(int i = 0; i < n; i++){
                maxi = max(maxi, matrix[i][j]);   // update column maximum
            }
            
            
            // Step 3: check if column maximum exists in set
            // if yes → it means element is min in row and max in column
            if(s.count(maxi)){
                ans.push_back(maxi);    // lucky number found
            }
        }
        
        
        return ans;                 // return all lucky numbers
    }
};
