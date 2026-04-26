class Solution {
public:
    
    // Hum 4 directions me move kar sakte hain:
    // upar, neeche, left, right
    vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    /*
        ==================== DETAILED INTUITION ====================

        Question bol raha hai hume check karna hai ki grid ke andar
        same character wale cells ka koi cycle exist karta hai ya nahi.

        Cycle ka simple matlab:
        Kisi ek cell se start karo,
        same letter wale adjacent cells me ghoomte raho,
        aur kisi point par wapas kisi already visited cell par pahunch jao
        WITHOUT using the same reverse edge only.

        Ye exactly undirected graph cycle detection jaisa hai.

        Socho:
        - Har cell ek node hai
        - Agar 2 adjacent cells ka character same hai,
          to unke beech edge hai.

        Ab graph me cycle detect karna hai.

        DFS use karenge.

        DFS me ek important cheez hoti hai:
        Jab hum current node se kisi neighbor me jaate hain,
        to obvious hai neighbor ke paas current node visited milega
        kyunki hum wahi se aaye hain.

        Lekin wo cycle nahi hota.

        Isliye parent track karna bahut zaroori hai.

        Rule:
        Agar koi visited neighbor milta hai
        aur wo parent nahi hai,
        iska matlab us node tak pahunchne ka ek aur path mila.

        => Closed loop ban gaya.
        => Cycle mil gaya.
    */


    // DFS function:
    // x,y = current cell
    // px,py = parent cell (jahan se hum current me aaye)
    // ch = jis character ke component me hum travel kar rahe hain
    bool dfs(int x, int y, int px, int py, char ch,
             vector<vector<bool>>& vis,
             vector<vector<char>>& grid) {
        
        // Current cell ko visited mark kar do
        vis[x][y] = true;

        // Ab current cell ke 4o neighbors check karenge
        for (auto &d : dirs) {
            int nx = x + d.first;
            int ny = y + d.second;

            // ------------------------------------------------
            // Step 1: Boundary ke bahar gaya to skip
            // ------------------------------------------------
            if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size())
                continue;

            // ------------------------------------------------
            // Step 2: Agar neighbor ka character alag hai
            // to us direction me ja hi nahi sakte
            // kyunki cycle same characters ka hi hona chahiye
            // ------------------------------------------------
            if (grid[nx][ny] != ch)
                continue;

            // ------------------------------------------------
            // Step 3: Parent ko ignore karo
            //
            // Example:
            // A -> B aaye
            // to B ko A visited milega hi
            // but wo cycle nahi hai
            //
            // isliye agar neighbor parent hai to continue
            // ------------------------------------------------
            if (nx == px && ny == py)
                continue;

            // ------------------------------------------------
            // Step 4:
            // Agar same char ka koi neighbor already visited hai
            // aur wo parent bhi nahi hai
            //
            // iska matlab hum kisi purane node tak
            // dusre raaste se wapas pahunch gaye.
            //
            // Means loop ban gaya.
            // Means cycle mil gaya.
            // ------------------------------------------------
            if (vis[nx][ny])
                return true;

            // ------------------------------------------------
            // Step 5:
            // Agar visited nahi hai to DFS lagao
            // aur andar kahin cycle milta hai to true return kara do
            // ------------------------------------------------
            if (dfs(nx, ny, x, y, ch, vis, grid))
                return true;
        }

        // Is current path se koi cycle nahi mila
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Visited matrix banayi taaki har cell ek hi baar process ho
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        /*
            Grid me multiple disconnected components ho sakte hain.

            Example:
            a a b
            a a b
            c c c

            Yahan 'a' ka component alag,
            'b' ka alag,
            'c' ka alag.

            Isliye har unvisited cell se DFS start karna padega.
        */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Agar ye cell abhi tak visit nahi hua
                if (!vis[i][j]) {

                    // Is component ka DFS start karo
                    // parent = -1,-1 kyunki starting node ka koi parent nahi
                    if (dfs(i, j, -1, -1, grid[i][j], vis, grid))
                        return true;
                }
            }
        }

        // Puri grid dekh li, kahin cycle nahi mila
        return false;
    }
};