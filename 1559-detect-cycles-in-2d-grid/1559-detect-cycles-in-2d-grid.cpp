class Solution {
public:
    // Grid ka size globally store kar rhe hain
    // taaki baar-baar function me pass na karna pade.
    int n, m;

    // DFS function
    //
    // i, j   -> Current cell
    // pi, pj -> Parent cell (jis cell se current cell par aaye hain)
    //
    // WHY parent pass kar rhe hain?
    // Kyuki DFS me jab current node ke neighbours dekhte hain,
    // tab parent already visited hoga.
    //
    // Agar parent ko ignore nahi karenge,
    // to har edge ko cycle samajh lenge.
    bool dfs(int i, int j, int pi, int pj,
             vector<vector<char>>& grid,
             vector<vector<int>>& vis) {

        // Current cell ko visited mark kar do
        // taaki dobara ispar DFS na chale.
        vis[i][j] = 1;

        // 4 possible directions
        // Up, Down, Left, Right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // Har direction me neighbour check karenge
        for (int k = 0; k < 4; k++) {

            int ni = i + dx[k];
            int nj = j + dy[k];

            // WHY Boundary Check?
            //
            // Grid ke bahar access karenge to
            // runtime error aa jayega.
            if (ni < 0 || nj < 0 || ni >= n || nj >= m)
                continue;

            // WHY same character hi check kar rhe hain?
            //
            // Question ke according cycle tabhi valid hai
            // jab saare connected cells ka character same ho.
            //
            // Alag character mila to us direction me
            // jaana hi nahi hai.
            if (grid[ni][nj] != grid[i][j])
                continue;

            // WHY visited neighbour check kar rhe hain?
            //
            // Agar neighbour already visited hai
            // aur wo parent bhi nahi hai,
            // iska matlab hum kisi aur path se
            // dobara isi node tak pahunch gaye.
            //
            // Yehi cycle ki definition hai.
            if (vis[ni][nj] && !(ni == pi && nj == pj))
                return true;

            // Agar neighbour abhi tak visit nahi hua,
            // to DFS continue karo.
            if (!vis[ni][nj]) {

                // Recursively poora connected component explore karo.
                bool res = dfs(ni, nj, i, j, grid, vis);

                // Agar niche kahin bhi cycle mil gayi,
                // to immediately true return kar do.
                //
                // WHY?
                // Kyuki hume sirf ye batana hai
                // ki cycle exist karti hai ya nahi.
                if (res)
                    return true;
            }
        }

        // Pure component me cycle nahi mili.
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {

        n = grid.size();
        m = grid[0].size();

        // visited array
        //
        // 0 -> Not Visited
        // 1 -> Visited
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // WHY poori grid traverse kar rhe hain?
        //
        // Ho sakta hai graph/grid disconnected ho.
        //
        // Matlab multiple alag-alag connected components ho sakte hain.
        //
        // Isliye har unvisited cell se
        // naya DFS start karna padega.
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                // Sirf unvisited cell se DFS chalayenge.
                //
                // WHY?
                // Visited component ko dobara explore karna
                // sirf extra work hoga.
                if (!vis[i][j]) {

                    // Parent initially exist nahi karta,
                    // isliye (-1, -1) pass kar rhe hain.
                    bool res = dfs(i, j, -1, -1, grid, vis);

                    // Agar kisi bhi component me cycle mil gayi,
                    // answer true hai.
                    if (res)
                        return true;
                }
            }
        }

        // Kisi bhi connected component me cycle nahi mili.
        return false;
    }
};

/*
---------------- WHY DFS Works ----------------

DFS ek connected component ko completely explore karta hai.

Traversal ke time:

1. Har cell sirf ek baar visit hota hai.

2. Agar koi visited neighbour milta hai,
   to do possibilities hain:

   (a) Wo parent hai
       -> Normal back edge hai.
       -> Cycle nahi hai.

   (b) Parent nahi hai
       -> Kisi dusre path se wapas isi cell tak aa gaye.
       -> Matlab cycle exist karti hai.

Isi logic ki wajah se cycle detect ho jati hai.

---------------- Time Complexity ----------------

Har cell maximum ek baar visit hota hai.

Har cell ke 4 neighbours check hote hain.

Overall TC = O(n × m)

---------------- Space Complexity ----------------

Visited array = O(n × m)

DFS Recursion Stack
Worst Case = O(n × m)

Overall SC = O(n × m)
*/