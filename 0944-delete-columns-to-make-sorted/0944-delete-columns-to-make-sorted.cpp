class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();//row
        int m=strs[0].size();//col
        int cnt=0;
        for(int col=0;col<m;col++){
            for(int row=0;row<n-1;row++){
                if(strs[row][col]>strs[row+1][col]){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};