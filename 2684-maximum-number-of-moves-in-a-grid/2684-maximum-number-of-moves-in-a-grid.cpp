class Solution {
public:
int n; // number of rows
int m; // number of columns

// possible row directions: up-right, right, down-right
vector<int> directions = {-1, 0, 1};

// DFS with memoization
int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp){
    // if already computed, return stored result
    if(dp[r][c] != -1) return dp[r][c];

    int moves = 0; // maximum moves from this cell

    // try all three directions
    for(int& dir : directions){
        int nr = r + dir; // new row
        int nc = c + 1;   // always move to next column

        // check boundaries and increasing condition
        if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] > grid[r][c]){
            moves = max(moves, 1 + dfs(nr, nc, grid, dp));
        }
    }

    // store result in dp and return
    return dp[r][c] = moves;
}

int maxMoves(vector<vector<int>>& grid) {
    n = grid.size();        // total rows
    m = grid[0].size();     // total columns

    // dp array for memoization
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int ans = 0; // final answer

    // start DFS from every row in first column
    for(int i = 0; i < n; i++){
        ans = max(ans, dfs(i, 0, grid, dp));
    }

    return ans; // return maximum moves
}
};
