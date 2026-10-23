
class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int r, int c, int num) {

        // INTUITION: Sudoku mein number tabhi valid hai jab woh
        // current row, column aur 3x3 box mein pehle se present na ho.

        // Check current row.
        for (int i = 0; i < 9; i++) {
            if (board[r][i] - '0' == num) return false;
        }

        // Check current column.
        for (int i = 0; i < 9; i++) {
            if (board[i][c] - '0' == num) return false;
        }

        // INTUITION: (r/3)*3 aur (c/3)*3 se us 3x3 box ka
        // top-left cell milta hai jisme current cell present hai.
        int x = (r / 3) * 3;
        int y = (c / 3) * 3;

        // Check all 9 cells of that 3x3 box.
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                if (board[i][j] - '0' == num) return false;
            }
        }

        // Teeno rules pass = number safely place kar sakte hain.
        return true;
    }

    bool f(vector<vector<char>>& board, int r, int c) {

        // INTUITION: Row 9 par pahunch gaye matlab saare 81 cells
        // process ho chuke hain aur koi conflict nahi mila.
        if (r == 9) return true;

        // Current row ke saare columns complete, ab next row par jao.
        if (c == 9) return f(board, r + 1, 0);

        // INTUITION: Given number ko change nahi karna; filled cell
        // ko skip karke agle cell ko solve karo.
        if (board[r][c] != '.') return f(board, r, c + 1);

        // INTUITION: Empty cell ke liye 1-9 try karenge.
        // Jo number rules follow kare, usse place karke aage badhenge.
        for (int j = 1; j <= 9; j++) {
            if (isSafe(board, r, c, j)) {

                board[r][c] = '0' + j; // CHOOSE: valid number place karo.

                // EXPLORE: Next cell solve karo; agar aage solution
                // nahi mila, toh current choice ko change karna padega.
                bool returnVal = f(board, r, c + 1);

                // Solution mil gaya, isliye true return karo aur
                // board ko restore mat karo.
                if (returnVal == true) return true;

                // UNDO: Ye number aage solution nahi de saka,
                // isliye cell empty karke next number try karo.
                board[r][c] = '.';
            }
        }

        // INTUITION: Koi bhi number work nahi kiya, toh previous
        // cell ki recursion ko doosri choice try karni padegi.
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        // INTUITION: Top-left se row-wise har cell solve karenge.
        // Backtracking automatically wrong choices ko undo karegi.
        f(board, 0, 0);
    }
};

/*
TC: O(9^E), where E = number of initially empty cells (worst-case upper bound).
    Each safety check is O(1) because the board is fixed at 9x9.

SC: O(E) recursion stack, at most O(81) = O(1) for a fixed board.
    Board is modified in place; no extra board is created.
*/
