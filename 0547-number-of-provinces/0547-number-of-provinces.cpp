class Solution {
public:
    /* =======================================================================
        🚀 PROBLEM: NUMBER OF PROVINCES (USING DFS)
        =======================================================================
        💡 DEEP INTUITION:
        - DFS ka matlab hai ek node pakdo aur uske raste jitni door tak ja 
          sakte ho, chale jao.
        - Isse ek baar mein ek poora "Connected Group" visit ho jata hai.
       =======================================================================
    */

    // 🔹 DFS Helper Function (Recursive)
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& vis) {
        // Current node ko visit mark karo
        vis[node] = true;

        // Ab is node ke saare padosi (neighbors) check karo
        for (int i = 0; i < isConnected.size(); i++) {
            // Agar connection hai (1) aur padosi abhi tak visit nahi hua
            if (isConnected[node][i] && !vis[i]) {
                // Turant us padosi ke andar ghus jao (Recursive call)
                dfs(i, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false); // Sabka status shuru mein 'Unvisited'
        int provinces = 0;

        // 🔹 Step 1: Har node par ja kar dekho
        for (int i = 0; i < n; i++) {
            // Agar node visited nahi hai, matlab naya group mila!
            if (!vis[i]) {
                provinces++; // Nayi province count karo
                
                // 🔹 Step 2: DFS bulao jo is poore group ko mark kar dega
                dfs(i, isConnected, vis);
            }
        }

        return provinces; // Final count return kar do
    }
};