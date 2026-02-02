class Solution {
public:
    int n;
    int m;
    int ans = 0;

    // 4 possible movement directions: down, up, right, left
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& grid, int sr, int sc, int rem) {

        // Agar grid ke bahar chale gaye
        // ya obstacle mila
        // ya already visited cell mila
        if(sr < 0 || sc < 0 || sr >= n || sc >= m ||
           grid[sr][sc] == -1 || grid[sr][sc] == -3)
            return;

        // Agar end cell (2) pe pahunch gaye
        if(grid[sr][sc] == 2) {

            // rem == 1 ka matlab:
            // end cell pe pahunchne se pehle saare cells visit ho chuke hain
            if(rem == 1) {
                ans++;   // ek valid unique path mila
            }

            // end cell se aage DFS nahi karna
            return;
        }

        // Current cell ki original value store kar li
        int temp = grid[sr][sc];

        // Current cell ko visited mark kar diya
        grid[sr][sc] = -3;

        // 4 directions me DFS call
        for(auto &dir : directions) {
            dfs(grid, sr + dir[0], sc + dir[1], rem - 1);
        }

        // Backtracking:
        // cell ko uski original value me wapas le aaye
        grid[sr][sc] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int sr, sc;
        int remCells = 0;

        // Total non-obstacle cells count kar rahe hain
        // aur start cell ka position nikal rahe hain
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // Obstacle (-1) ke alawa sab cells count honge
                if(grid[i][j] != -1)
                    remCells++;

                // Start cell ka row aur column store
                if(grid[i][j] == 1) {
                    sr = i;
                    sc = j;
                }
            }
        }

        // Start cell se DFS start
        dfs(grid, sr, sc, remCells);

        // Total unique paths return
        return ans;
    }
};
