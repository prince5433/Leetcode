class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    bool find(vector<vector<char>>& board, int i, int j, int idx, string& word) {
        // if we matched all characters -> word found
        if (idx == word.size()) return true;

        int n = board.size();
        int m = board[0].size();

        // boundary + visited check
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '#') return false;

        // character mismatch
        if (board[i][j] != word[idx]) return false;

        // mark current cell visited
        char temp = board[i][j];
        board[i][j] = '#';

        // try all 4 directions
        for (int k = 0; k < 4; k++) {
            int newi = i + directions[k][0];
            int newj = j + directions[k][1];

            if (find(board, newi, newj, idx + 1, word)) return true;
        }

        // backtrack: restore cell
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        // start DFS from every cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && find(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
};
