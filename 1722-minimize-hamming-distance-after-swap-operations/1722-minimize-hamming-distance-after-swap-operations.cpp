

class Solution {
public:
    /**
     * ✅ Intuition: 
     * Agar hum index A aur B ko swap kar sakte hain, aur B aur C ko bhi, 
     * toh iska matlab A, B, aur C ek "Community" ya "Group" ka hissa hain.
     * Is group ke andar ke elements ko hum kisi bhi order mein arrange kar sakte hain.
     * Hum DSU use karenge groups banane ke liye, aur phir har group ke 
     * elements ka ek "Pool" (frequency map) banayenge.
     */

    // ✅ FIND function: Ye batata hai ki kisi index ka "Ultimate Boss" (Root) kaun hai.
    int find(vector<int> &parent, int x) {
        // Agar main khud hi apna parent hoon, toh main hi boss hoon.
        if (parent[x] == x) return x;
        
        // Path Compression: Agli baar dhoondne mein mehnat na ho, 
        // isliye raste ke saare nodes ko direct boss se connect kar do.
        return parent[x] = find(parent, parent[x]);
    }

    // ✅ UNION function: Do alag-alag groups ko ek saath jodne ke liye.
    void Union(vector<int> &parent, vector<int> &rank, int a, int b) {
        int root_a = find(parent, a);
        int root_b = find(parent, b);

        // Agar dono pehle se hi same group (boss) ke hain, toh kuch nahi karna.
        if (root_a == root_b) return;

        // Union by Rank: Chhote tree ko hamesha bade tree ke niche lagao 
        // taaki tree ki height zyada na badhe aur search fast rahe.
        if (rank[root_a] <= rank[root_b]) {
            parent[root_a] = root_b;
            rank[root_b]++;  
        } else {
            parent[root_b] = root_a;
            rank[root_a]++;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        
        // Step 1: DSU setup (Sabko initially apna boss bana do)
        vector<int> parent(n);
        vector<int> rank(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i; 
        }

        // Step 2: Connections (Allowed swaps ko use karke groups/communities banao)
        // 
        for (auto& swap : allowedSwaps) {
            Union(parent, rank, swap[0], swap[1]);
        }

        // Step 3: Grouping elements (Har group ka ek "Khazaana" ya Pool banao)
        // unordered_map<BossIndex, unordered_map<ElementValue, Frequency>>
        unordered_map<int, unordered_map<int, int>> groupPool;
        for (int i = 0; i < n; i++) {
            // Pata karo ye index kis group ka part hai
            int root = find(parent, i);
            // Us group ke khazaane mein source ka element bhar do
            groupPool[root][source[i]]++;
        }

        int hammingDist = 0;

        // Step 4: Target Matching (Check karo ki kya target elements available hain?)
        for (int i = 0; i < n; i++) {
            // Is index ka boss kaun hai? (Kyunki swapping sirf isi ke group mein hogi)
            int root = find(parent, i);
            int requiredVal = target[i];

            // Kya is group ke pool mein wo element mil sakta hai?
            if (groupPool[root][requiredVal] > 0) {
                // Haan mil gaya! Pool se ek count kam karo (element use ho gaya)
                groupPool[root][requiredVal]--; 
            } else {
                // Nahi mila! Iska matlab ye position target se hamesha alag rahegi
                hammingDist++;
            }
        }

        // Final result: Itne mismatches minimum honge hi honge.
        return hammingDist;
    }
};