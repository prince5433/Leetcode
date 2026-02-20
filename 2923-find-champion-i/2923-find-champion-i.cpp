class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {

        int n = grid.size();        // total teams (rows)
        int m = grid[0].size();    // total columns (same as n, since square matrix)

        int maxi = -1;             // stores maximum number of wins found so far
        int champ = -1;            // stores index of champion team

        // iterate through each team (each row)
        for(int i = 0; i < n; i++){

            int cnt = 0;           // count wins of current team

            // count number of 1s in current row
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) cnt++;
            }

            // if current team has more wins than previous maximum
            if(cnt > maxi){
                maxi = cnt;       // update maximum wins
                champ = i;        // update champion index
            }
        }

        return champ;              // return champion team index
    }
};