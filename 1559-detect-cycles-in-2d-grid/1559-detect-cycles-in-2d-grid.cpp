class Solution {
public:
    vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    // DFS function with parent tracking
    bool dfs(int x, int y, int px, int py, char ch, vector<vector<bool>>& vis, vector<vector<char>>& grid) {
        vis[x][y] = true;

        for (auto &d : dirs) {
            int nx = x + d.first;
            int ny = y + d.second;

            // Skip out of bounds
            if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) continue;

            // Skip different letter
            if (grid[nx][ny] != ch) continue;

            // Skip parent cell
            if (nx == px && ny == py) continue;

            // If visited and not parent → cycle detected
            if (vis[nx][ny]) return true;

            // DFS recursively
            if (dfs(nx, ny, x, y, ch, vis, grid)) return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Run DFS from each unvisited cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1, grid[i][j], vis, grid)) return true;
                }
            }
        }

        return false;
    }
};
