class Solution {
public:
    /* =======================================================================
        🚀 PROBLEM: NUMBER OF PROVINCES (CONNECTED COMPONENTS)
        =======================================================================
        💡 DEEP INTUITION:
        - Har node ko check karo. Agar node visited nahi hai, matlab ek naya 
          group (province) mil gaya.
        - Phir BFS chala kar us group ke saare nodes ko 'Visited' mark kar do 
          taaki wo dobara count na ho jayein.
       =======================================================================
    */
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false); // Tracks visited nodes
        int p = 0; // Provinces count

        // 🔹 Step 1: Har node ko scan karo
        for (int i = 0; i < n; i++) {
            // Agar node visited nahi hai, toh naya component shuru karo
            if (!vis[i]) {
                p++; // Naya province mil gaya!
                
                // 🔹 Step 2: BFS se poore component ko visit karo
                queue<int> q;
                q.push(i);
                vis[i] = true;

                while (!q.empty()) {
                    int curr = q.front(); 
                    q.pop();

                    // Adjacency Matrix traverse karke padosi (neighbors) dhundo
                    for (int j = 0; j < n; j++) {
                        // Agar curr aur j connected hain aur j visited nahi hai
                        if (isConnected[curr][j] && !vis[j]) {
                            vis[j] = true; // Mark as visited
                            q.push(j);     // Agla level explore karne ke liye queue mein daalo
                        }
                    }
                }
            }
        }
        return p; // Total provinces return kar do
    }
};