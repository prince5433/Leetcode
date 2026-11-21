#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // adj[u] mein node u ke saare children store honge.
    // list<int> use ki hai, as requested.
    vector<list<int>> adj;

    // resultSize[i] = node i ke final subtree mein
    // total kitne nodes hain.
    vector<int> resultSize;

    // last[c] = current DFS path mein character c
    // wala sabse recent (nearest) ancestor.
    //
    // c = 0 to 25, representing 'a' to 'z'.
    // -1 means abhi tak aisa ancestor nahi mila.
    vector<int> last;


    void dfs(int currNode, string& s, vector<int>& parent) {

        // Current node ka character index nikalo.
        //
        // Example:
        // s[currNode] = 'c'
        // c = 'c' - 'a' = 2
        int c = s[currNode] - 'a';


        // DFS path mein current node se pehle
        // isi character ka nearest ancestor save karo.
        //
        // Agar ancestor nahi hai, toh nearestAncestor = -1.
        int nearestAncestor = last[c];


        // Ab current node ko is character ka latest node bana do.
        //
        // Iske baad current node ke children ki DFS mein
        // last[c] current node ko represent karega.
        last[c] = currNode;


        // Current node ke saare children explore karo.
        //
        // DFS pehle child ka poora subtree process karega,
        // phir next child par jayega.
        for(int child : adj[currNode]) {

            dfs(child, s, parent);
        }


        // ---------------- BACKTRACKING ----------------
        //
        // Current node ke saare children process ho gaye.
        //
        // Ab DFS current node se wapas uske parent ki taraf ja rahi hai.
        //
        // Isliye last[c] ko us purani value par restore karo
        // jo current node visit karne se pehle thi.
        //
        // Ye zaroori hai, warna ek sibling ke nodes ko
        // doosre sibling ka node galti se ancestor samajh sakte hain.
        last[c] = nearestAncestor;


        // Root node 0 ka parent nahi hota.
        // Isliye root ke liye parent update karne ki zarurat nahi.
        if(currNode != 0) {

            // Initially current node ka original parent lo.
            int newParent = parent[currNode];


            // Agar same character ka nearest ancestor mila,
            // toh current node ko us ancestor ke under move karna hai.
            //
            // Example:
            // Current node ka character 'b' hai.
            // DFS path mein nearest 'b' ancestor node 2 hai.
            // Toh current node ka new parent node 2 hoga.
            if(nearestAncestor != -1) {

                newParent = nearestAncestor;
            }


            // Current node ka final parent update karo.
            parent[currNode] = newParent;


            // Current node ka poora subtree ab newParent ke subtree
            // ka part hai, isliye uska size newParent mein add karo.
            //
            // DFS postorder mein chal rahi hai:
            // pehle children ke sizes calculate hue,
            // phir current node ka size parent ko add hoga.
            resultSize[newParent] += resultSize[currNode];
        }
    }


    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();


        // Adjacency list ko n nodes ke liye initialize karo.
        // Clear karna bhi zaroori hai, taaki purane test case
        // ka graph next call mein reuse na ho.
        adj.clear();
        adj.resize(n);


        // Parent array se original tree ki adjacency list banao.
        //
        // parent[i] = i ka parent
        //
        // Isliye edge:
        // parent[i] -> i
        //
        // Root node 0 ka parent nahi hota, isliye i = 1 se start.
        for(int i = 1; i < n; i++) {

            int u = parent[i];
            int v = i;

            // u ke children mein v add karo.
            adj[u].push_back(v);
        }


        // Initially har node apna subtree khud hota hai.
        //
        // Isliye har node ka initial subtree size = 1.
        resultSize.assign(n, 1);


        // 26 lowercase English characters ke liye
        // nearest ancestor track karenge.
        //
        // Initially kisi character ka ancestor nahi mila.
        last.assign(26, -1);


        // Root se DFS start karo.
        //
        // DFS ke andar:
        // 1. Same character ka nearest ancestor track hoga.
        // 2. Node ka final parent update hoga.
        // 3. Subtree sizes calculate hongi.
        dfs(0, s, parent);


        // Har node ka final subtree size return karo.
        return resultSize;
    }
};