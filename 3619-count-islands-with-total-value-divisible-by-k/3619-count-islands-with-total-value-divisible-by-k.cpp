class Solution {
public:
    int n;
    int m;

    void dfs(vector<vector<int>>& grid, int i, int j, long long& sum) {

        // BASE CASE:
        // Agar hum grid ki boundary ke bahar chale gaye,
        // ya cell 0 (water) hai, ya -1 (already visited) hai,
        // toh is direction mein aage explore nahi karna.
        if (i < 0 || j < 0 || i >= n || j >= m ||
            grid[i][j] == -1 || grid[i][j] == 0) {
            return;
        }

        // SUM UPDATE:
        // Current cell ki original value island ke total sum mein add karo.
        // sum ko reference (&) se pass kiya hai, isliye har DFS call
        // ka contribution same sum variable mein add hoga.
        sum += grid[i][j];

        // MARK VISITED:
        // Cell ko -1 mark kar do, taaki doosre DFS calls mein
        // isi cell ko dobara count na karein aur infinite recursion na ho.
        // Sum mein original value add karne ke BAAD hi mark karna hai.
        grid[i][j] = -1;

        // EXPLORE:
        // Current cell ke chaar neighbours check karo.
        // Sirf valid, non-zero aur unvisited neighbours process honge.
        dfs(grid, i + 1, j, sum); // Neeche
        dfs(grid, i - 1, j, sum); // Upar
        dfs(grid, i, j + 1, sum); // Right
        dfs(grid, i, j - 1, sum); // Left
    }

    int countIslands(vector<vector<int>>& grid, int k) {

        // Grid ki dimensions save karo, taaki DFS mein boundaries check kar sakein.
        n = grid.size();
        m = grid[0].size();

        // Ans: kitne connected components ka sum k se divisible hai.
        int ans = 0;

        // Har cell ko starting point banane ki koshish karo.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Agar cell positive hai, toh woh abhi tak visited nahi hua
                // aur ek naye island ka starting point ho sakta hai.
                if (grid[i][j] > 0) {

                    // Har naye island ka sum zero se start hoga.
                    // Alag islands ka sum aapas mein mix nahi hona chahiye.
                    long long sum = 0;

                    // DFS poore connected island ko visit karega
                    // aur uske saare cell values sum mein add karega.
                    dfs(grid, i, j, sum);

                    // DFS complete hone ke baad poore island ka sum mil gaya.
                    // Agar sum k se completely divisible hai,
                    // toh is island ko answer mein count karo.
                    if (sum % k == 0) {
                        ans++;
                    }
                }

                // Agar cell 0 ya -1 hai, toh naya DFS start nahi hoga.
                // 0 water hai aur -1 visited cell ko represent karta hai.
            }
        }

        // Sabhi connected components process karne ke baad final answer.
        return ans;
    }
};

/*
TIME COMPLEXITY: O(n * m)
Har cell maximum ek baar visit hota hai, kyunki DFS use -1 mark kar deta hai.

SPACE COMPLEXITY: O(n * m) worst case
Agar saare cells ek connected component mein hain, toh recursion stack
mein maximum O(n * m) calls ho sakti hain.
*/