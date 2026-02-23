class Solution {
public:
    int n;
    int m;
    
    // 4 possible directions (right, left, down, up)
    vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        // Boundary check + cannot visit 0 cell
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)
            return 0;

        // DO
        int gold = grid[i][j];
        grid[i][j] = 0;   // mark visited

        int best = 0;

        // EXPLORE all 4 directions
        for(auto d : dirs) {
            int nr = i + d.first;
            int nc = j + d.second;
            best = max(best, dfs(grid, nr, nc));
        }

        // UNDO (backtrack)
        grid[i][j] = gold;

        return gold + best;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] > 0)   // start only from gold cells
                    ans = max(ans, dfs(grid, i, j));
            }
        }

        return ans;
    }
};