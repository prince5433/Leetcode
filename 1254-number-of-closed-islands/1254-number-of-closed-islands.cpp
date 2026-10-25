
class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& grid, int i, int j) {

        // BASE CASE:
        // DFS 4 directions mein move karta hai, isliye grid ke bahar ja sakta hai.
        // Agar cell 1 hai, toh woh water hai ya pehle hi visit ho chuka hai.
        // Aise cell se aage explore karne ka koi fayda nahi, isliye return.
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 1) {
            return;
        }

        // CURRENT CELL KO VISIT MARK KARO:
        // grid[i][j] == 0 ka matlab yahan land hai.
        // Ise 1 banane se pata chalega ki is cell ko process kar chuke hain.
        // Isse infinite recursion nahi hoga aur same island dobara count nahi hoga.
        grid[i][j] = 1;

        // 4 DIRECTIONS MEIN DFS:
        // Island ek single 0 nahi, balki connected 0s ka group ho sakta hai.
        // Isliye current cell ke chaaron neighbours explore karo.
        // DFS har connected 0 ko 1 bana dega.
        dfs(grid, i + 1, j); // Down: neeche wala connected land
        dfs(grid, i - 1, j); // Up: upar wala connected land
        dfs(grid, i, j + 1); // Right: right wala connected land
        dfs(grid, i, j - 1); // Left: left wala connected land
    }

    int closedIsland(vector<vector<int>>& grid) {

        m = grid.size();       // Grid mein total rows
        n = grid[0].size();    // Grid mein total columns

        // STEP 1: BOUNDARY SE CONNECTED LAND HATAO
        //
        // INTUITION:
        // Closed island woh hai jo grid ki boundary ko touch nahi karta.
        // Agar boundary par 0 hai, toh uska island closed nahi ho sakta.
        // Us boundary 0 se DFS chala kar poore connected island ko 1 bana do.
        //
        // WHY IF grid[i][0] == 0?
        // Agar cell pehle se 1 hai, toh DFS call karna unnecessary hai.
        // Sirf land (0) milne par hi DFS chala rahe hain.

        for (int i = 0; i < m; i++) {

            // LEFT COLUMN:
            // Har row ka first cell left boundary par hota hai.
            // Agar yahan 0 mila, toh isse connected saare 0s non-closed hain.
            if (grid[i][0] == 0) {
                dfs(grid, i, 0);
            }

            // RIGHT COLUMN:
            // Har row ka last cell right boundary par hota hai.
            // Is boundary se connected land ko bhi eliminate karna hai.
            if (grid[i][n - 1] == 0) {
                dfs(grid, i, n - 1);
            }
        }

        for (int j = 0; j < n; j++) {

            // FIRST ROW:
            // Har column ka topmost cell upper boundary par hota hai.
            // Agar 0 mila, toh uska connected island closed nahi hai.
            if (grid[0][j] == 0) {
                dfs(grid, 0, j);
            }

            // LAST ROW:
            // Har column ka bottommost cell lower boundary par hota hai.
            // Is boundary se connected saare 0s ko bhi 1 bana do.
            if (grid[m - 1][j] == 0) {
                dfs(grid, m - 1, j);
            }
        }

        // STEP 2: BAAKI BACHE HUE CLOSED ISLANDS COUNT KARO
        //
        // INTUITION:
        // Humne boundary se connected saare 0s ko 1 bana diya.
        // Ab jo 0s bache hain, woh boundary tak connected nahi hain.
        // Isliye har remaining connected group ek closed island hai.

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Agar ab bhi 0 mila, toh ek naya closed island mila.
                if (grid[i][j] == 0) {

                    ans++; // Is naye island ko count karo.

                    // WHY DFS AGAIN?
                    // Ek island mein multiple connected 0s ho sakte hain.
                    // DFS un sabko 1 bana dega.
                    // Isliye agle cells check karte waqt same island dobara count nahi hoga.
                    dfs(grid, i, j);
                }
            }
        }

        // Saare closed islands count ho chuke hain.
        return ans;
    }
};

// TC: O(m * n)
// Har cell maximum ek baar 0 se 1 banta hai; total grid traversal O(m*n) hai.

// SC: O(m * n) worst case
// DFS recursion stack mein worst case mein O(m*n) cells ho sakte hain.
