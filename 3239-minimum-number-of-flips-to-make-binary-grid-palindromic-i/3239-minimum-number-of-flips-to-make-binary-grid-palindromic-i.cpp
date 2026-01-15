class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int rf=0;
        for(int row=0;row<n;row++){
          int l=0;
          int r=m-1;
          while(l<r){
 if(grid[row][l]!=grid[row][r]) {
                rf++;
                
            }
            l++;
                r--;
        }
          }
           
         int cf=0;
        for(int col=0;col<m;col++){
          int l=0;
          int r=n-1;
          while(l<r){
             if(grid[l][col]!=grid[r][col]) {
                cf++;
            }
              l++;
                r--;
        }
          }
           
        return min(rf,cf);
    }
};