class Solution {
public:
    // Har cell tak entrance se pahunchne ki minimum distance store karega.
    vector<vector<int>> dist;

    // 4 possible directions: down, up, right, left.
    // dirs[i][0] = row change, dirs[i][1] = column change.
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();       // Maze mein total rows
        int m = maze[0].size();    // Maze mein total columns

        // Distance matrix ko maze ke size ka banao.
        // -1 ka matlab hai ki cell abhi visit nahi hua hai.
        dist.assign(n, vector<int>(m, -1));

        // BFS entrance se start hoga.
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});

        // Entrance ki distance 0 hai, kyunki hum wahi se start kar rahe hain.
        dist[entrance[0]][entrance[1]] = 0;

        while (!q.empty()) {
            // Queue se current cell nikalo.
            auto [r, c] = q.front();
            q.pop();

            // Exit woh empty cell hai jo maze ke border par ho.
            // Entrance ko exit nahi maan sakte, chahe woh border par hi kyun na ho.
            if ((r == 0 || c == 0 || r == n-1 || c == m-1) &&
                !(r == entrance[0] && c == entrance[1])) {
                return dist[r][c];
            }

            // Current cell ke 4 neighbouring cells check karo.
            for (auto d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];

                // Neighbour valid tabhi hai jab:
                // 1. Maze ke bounds ke andar ho.
                // 2. Pehle visit na hua ho (dist == -1).
                // 3. Wall na ho, yani cell empty ho.
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    dist[nr][nc] == -1 && maze[nr][nc] == '.') {

                    // Neighbour tak pahunchne mein current cell se 1 step extra lagega.
                    // Distance assign karna us cell ko visited mark bhi karta hai.
                    dist[nr][nc] = dist[r][c] + 1;

                    // Valid neighbour ko BFS queue mein add karo.
                    q.push({nr, nc});
                }
            }
        }

        // Agar BFS complete ho gaya aur koi exit nahi mila, toh -1 return karo.
        return -1;
    }
};