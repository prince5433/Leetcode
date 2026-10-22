class Solution {
public:
    vector<vector<char>> grid;
    int count = 0;

    bool canPlaceQueen(int row, int col, int n) {

        // INTUITION:
        // Row-by-row placement hai, isliye sirf upar check karna hai.
        // Queen same column ya diagonal mein attack kar sakti hai.

        // 1. Same column check
        for (int i = row - 1; i >= 0; i--) {
            if (grid[i][col] == 'Q')
                return false;
        }

        // 2. Upper-left diagonal check
        // Har step par row aur column dono decrease hote hain.
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0; i--, j--) {
            if (grid[i][j] == 'Q')
                return false;
        }

        // 3. Upper-right diagonal check
        // Row decrease hoti hai aur column increase hota hai.
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n; i--, j++) {
            if (grid[i][j] == 'Q')
                return false;
        }

        // Koi attack nahi kar raha, position safe hai.
        return true;
    }

    void f(int row, int n) {

        // BASE CASE:
        // row == n matlab har row mein queen place ho chuki hai.
        // Ek valid arrangement mil gaya, isliye count badhao.
        // Board ko store karne ki zaroorat nahi hai.
        if (row == n) {
            count++;
            return;
        }

        // Current row mein har column try karo.
        for (int col = 0; col < n; col++) {

            if (canPlaceQueen(row, col, n)) {

                // CHOOSE: Safe cell par queen place karo.
                grid[row][col] = 'Q';

                // EXPLORE: Agli row mein queen place karne ki
                // saari possible arrangements check karo.
                f(row + 1, n);

                // UNDO: Queen hatao taaki next column try ho sake.
                grid[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {

        // Har call ke liye fresh board aur count initialize karo.
        count = 0;
        grid.assign(n, vector<char>(n, '.'));

        // Row 0 se backtracking start karo.
        f(0, n);

        // Sirf total valid arrangements return karo.
        return count;
    }
};

/*
TC:
  Search worst-case upper bound: O(N * N!).
  Har candidate position ki safety check O(N) leti hai.

SC:
  O(N^2) for the board + O(N) recursion stack.
  Total auxiliary space O(N^2).
  Valid boards store nahi karte, isliye result-storage space nahi hai.
*/