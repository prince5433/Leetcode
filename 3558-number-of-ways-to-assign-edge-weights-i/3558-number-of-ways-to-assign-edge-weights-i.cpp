class Solution {
public:
    // Fast Exponentiation (Binary Exponentiation)
    // Intuition: O(N) loop ki jagah power ko half karte jao taaki calculation O(log N) mein ho jaye.
    long long power(long long base, long long exp, int mod) {
        
        // Base case: Kisi bhi number ki power 0 humesha 1 hoti hai
        if (exp == 0)
            return 1;

        // Recursion: Pehle (exp / 2) ka result nikal lo
        long long half = power(base, exp / 2, mod);

        // Result ko usi se multiply kar do (half * half)
        // Modulo yahan lagana zaroori hai taaki integer overflow na ho
        long long res = (half * half) % mod;

        // Agar power odd thi (jaise 2^5), toh ek baar original base aur multiply karna padega
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }

        return res;
    }

    // DFS (Depth First Search) to find maximum depth from root (Node 1)
    void dfs(int node, int depth, vector<bool>& visited, vector<vector<int>>& adj, int& maxdepth) {
        
        // Current node par aate hi usko mark kar do, taaki wapas ulte raaste na chale jayein
        visited[node] = true;

        // Har level par check karo ki kya humein naya sabse deep rasta mil gaya hai?
        maxdepth = max(maxdepth, depth);

        // Saare padosiyon (neighbors) ko check karo
        for (auto neigh : adj[node]) {
            // Agar neighbor pehle visit nahi hua, toh uske andar ghuso (depth 1 se badha kar)
            if (!visited[neigh]) {
                dfs(neigh, depth + 1, visited, adj, maxdepth);
            }
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        
        // Tree ki basic property: N nodes wale tree mein hamesha (N-1) edges hoti hain.
        int n = edges.size() + 1;

        // Adjacency List (Graph banane ke liye)
        // Size (n + 1) rakha hai kyunki nodes 1 se leke N tak labeled hain (0-indexed nahi hain)
        vector<vector<int>> adj(n + 1);

        // Edges ko traverse karke undirected tree build karo
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int maxdepth = 0;
        
        // History track karne ke liye ki kaunsa node visit ho chuka hai
        vector<bool> visited(n + 1, false);

        // Node 1 (root) se start karo, initial depth 0 maankar
        dfs(1, 0, visited, adj, maxdepth);

        // Problem constraints mein diya hai ki answer bohot bada ho sakta hai
        const int MOD = 1e9 + 7;

        // Edge case: Agar tree mein bas 1 hi node ho (0 edges), 
        // toh sum odd banane ka koi tareeqa hi nahi hai.
        if (maxdepth == 0)
            return 0;

        /*
        ---------------- INTUITION BEHIND THE MATH ----------------
        
        DFS humein root se kisi sabse deep leaf node tak ka rasta dega.
        Maan lo us raste mein 'D' edges hain (maxdepth = D).
        
        Goal: Un 'D' edges ka sum ODD hona chahiye. (Weights sirf 1 ya 2 ho sakte hain).
        
        Logic:
        - Shuru ki (D - 1) edges ko tum koi bhi weight dedo (1 ya 2).
        - Uska kuch bhi sum aaye (Even ya Odd).
        - Jo aakhri 1 edge bachti hai, wo majboor hoti hai balance karne ke liye!
          -> Agar purana sum Even hai, aakhri edge ko '1' (Odd) lena padega.
          -> Agar purana sum Odd hai, aakhri edge ko '2' (Even) lena padega.
        
        Iska matlab aakhri edge ke paas koi azaadi (choice) nahi hai.
        Choice sirf shuru ki (D - 1) edges ke paas hai (har ek ke paas 2 choices).
        
        Isliye total valid tarike = 2 * 2 * 2 ... (D-1) baar = 2^(maxdepth - 1).
        -----------------------------------------------------------
        */

        // Fast exponentiation use karke answer return kar do modulo ke sath
        return power(2, maxdepth - 1, MOD);
    }
};