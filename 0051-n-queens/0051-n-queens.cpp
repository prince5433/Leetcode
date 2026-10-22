class Solution {
public:
    vector<vector<char>> grid;
    vector<vector<string>> result;

    bool canPlaceQueen(int row, int col, int n) {

        /*
        INTUITION:
        Queen same row, same column aur diagonal mein
        attack kar sakti hai.

        Hum row-by-row queens place kar rahe hain.
        Isliye current row se neeche abhi koi queen nahi hai.
        Humein sirf upar ki rows check karni hain.

        Agar column aur dono upper diagonals safe hain,
        toh current cell par queen place kar sakte hain.
        */

        // 1. SAME COLUMN CHECK:
        // Current column mein upar ki har row check karo.
        // Agar Q mil gayi, toh dono queens same column mein hongi
        // aur ek doosre ko attack kar sakti hain.
        for (int i = row - 1; i >= 0; i--) {
            if (grid[i][col] == 'Q')
                return false;
        }

        // 2. UPPER-LEFT DIAGONAL CHECK:
        // Diagonal mein move karne par row aur column
        // dono ek-ek karke decrease hote hain.
        // i >= 0 aur j >= 0 board ki boundaries hain.
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0; i--, j--) {

            // Queen milne ka matlab current position unsafe hai.
            if (grid[i][j] == 'Q')
                return false;
        }

        // 3. UPPER-RIGHT DIAGONAL CHECK:
        // Is diagonal mein row decrease hoti hai,
        // lekin column increase hota hai.
        // j < n check karta hai ki hum board ke right edge
        // ke bahar na chale jaayein.
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n; i--, j++) {

            if (grid[i][j] == 'Q')
                return false;
        }

        // Koi queen column ya upper diagonal mein nahi mili,
        // toh current cell safe hai.
        return true;
    }

    void f(int row, int n) {

        /*
        INTUITION:
        f(row, n) ka kaam current row mein queen place karna hai.

        Har column try karenge:
        1. Safe hua toh queen rakhenge.
        2. Next row solve karne ke liye recursion chalayenge.
        3. Return hone par queen hata kar next column try karenge.

        Is process ko CHOOSE -> EXPLORE -> UNDO kehte hain.
        */

        // BASE CASE:
        // Valid rows 0 se n-1 tak hain.
        // row == n hone ka matlab sabhi n rows mein queen
        // successfully place ho gayi.
        if (row == n) {

            vector<string> temp;

            // grid char matrix hai, lekin answer ka format
            // vector<string> hai. Isliye har row ko string banate hain.
            for (int i = 0; i < n; i++) {
                string res = "";

                for (int j = 0; j < n; j++) {
                    // Current row ke characters string mein add karo.
                    res += grid[i][j];
                }

                // Complete row ko current board mein store karo.
                temp.push_back(res);
            }

            // Ek valid board mil gaya; ise saare answers mein save karo.
            // Copy save hoti hai, isliye baad mein grid undo hone se
            // result mein stored solution change nahi hoga.
            result.push_back(temp);
            return;
        }

        // Current row mein har column ko candidate position maan kar
        // try karo. Ho sakta hai kuch columns unsafe hon.
        for (int col = 0; col < n; col++) {

            // Queen sirf safe position par hi place karni hai.
            if (canPlaceQueen(row, col, n)) {

                // CHOOSE:
                // Current row aur column par queen place karo.
                grid[row][col] = 'Q';

                // EXPLORE:
                // Ab current row complete hai, next row solve karo.
                // Recursive call aage ke possible placements explore karegi.
                f(row + 1, n);

                // UNDO / BACKTRACK:
                // Recursion return ho gayi, toh is branch ki exploration
                // complete hai. Queen hata kar board restore karo.
                //
                // WHY?
                // Taaki isi row ka next column try karte waqt purani
                // queen galti se board par present na rahe.
                grid[row][col] = '.';
            }
        }

        // Agar current row ke saare columns try ho gaye,
        // toh function previous row wali call mein return karega.
        // Wahan previous queen undo hogi aur doosri choice try hogi.
    }

    vector<vector<string>> solveNQueens(int n) {

        // Same Solution object dobara use ho toh purane answers
        // ya board ki state naye test case mein carry na ho.
        grid.clear();
        result.clear();

        // N x N empty board banao.
        // '.' means empty cell; 'Q' means queen.
        grid.resize(n, vector<char>(n, '.'));

        // Row 0 se search shuru karo.
        f(0, n);

        // Saare valid board arrangements return karo.
        return result;
    }
};

/*
TIME COMPLEXITY (TC):
- Search ka worst-case upper bound: O(N * N!).
  Row-by-row placement mein har row ke liye possible columns
  explore hote hain, aur safety check worst case O(N) leta hai.
- S valid solutions store karne ke liye O(S * N^2) additional
  time lagta hai, kyunki har solution mein N x N board copy hota hai.

SPACE COMPLEXITY (SC):
- grid: O(N^2)
- Recursion stack: O(N), kyunki maximum N rows tak recursion jaati hai.
- Stored results: O(S * N^2)
- Output ko exclude karne par auxiliary space: O(N^2).
*/