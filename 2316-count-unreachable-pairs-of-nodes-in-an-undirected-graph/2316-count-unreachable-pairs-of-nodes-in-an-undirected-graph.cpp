
class Solution {
public:

    // FIND FUNCTION:
    // Kisi bhi node ka ultimate parent (leader/root) find karta hai.
    // Ek connected component ke saare nodes ka root same hota hai.
    int find(vector<int> &parent, int x) {

        // Agar parent[x] == x hai, iska matlab x khud apne
        // component ka root/leader hai.
        if(parent[x] == x) return x;

        // Agar x khud root nahi hai, toh uske parent ka root find karo.
        // Path Compression:
        // Directly x ko uske ultimate parent se connect kar do.
        // Isse future find operations fast ho jaate hain.
        return parent[x] = find(parent, parent[x]);
    }


    // UNION BY SIZE:
    // Do nodes ke connected components ko merge karta hai.
    // Jo component chhota hai, use bade component ke neeche attach karte hain.
    void Union(vector<int> &parent, vector<int> &size, int a, int b) {

        // Dono nodes ke ultimate parents find karo.
        // Humein actual nodes ko nahi, unke components ke roots ko merge karna hai.
        a = find(parent, a);
        b = find(parent, b);

        // Agar dono ka root same hai, toh dono pehle se connected hain.
        // Dobara merge karne ki zarurat nahi hai.
        if(a == b) return;

        // Check karo ki kaunsa component chhota hai.
        if(size[a] <= size[b]) {

            // Component A ke root ko Component B ke root ke neeche attach karo.
            parent[a] = b;

            // Ab dono components merge ho gaye hain.
            // Isliye naye root B ki size mein A ki size add karo.
            size[b] += size[a];

        } else {

            // Yahan Component B chhota hai.
            // Isliye B ko Component A ke neeche attach kar do.
            parent[b] = a;

            // Naye root A mein dono components ki sizes add karo.
            size[a] += size[b];
        }
    }


    long long countPairs(int n, vector<vector<int>>& edges) {

        // STEP 1: DSU ke liye arrays initialize karo.

        // parent[i] batayega ki node i ka parent kaun hai.
        // Initially har node apna khud ka parent hai.
        vector<int> parent(n);

        // size[i] batayega ki root i wale component mein kitne nodes hain.
        // Initially har node akela hai, isliye har component ka size 1 hai.
        vector<int> size(n, 1);

        // Har node ko initially uska khud ka parent bana do.
        for(int i = 0; i < n; i++) {

            // Initially har node ek separate component hai.
            parent[i] = i;
        }


        // STEP 2: Edge list ke through connected components merge karo.

        // Har edge batati hai ki u aur v directly connected hain.
        for(auto &e : edges) {

            // Current edge ka first node.
            int u = e[0];

            // Current edge ka second node.
            int v = e[1];

            // Dono nodes ke components ko merge kar do.
            // Agar already connected hain toh Union kuch nahi karega.
            Union(parent, size, u, v);
        }


        // STEP 3: Har connected component ka size ek array mein store karo.

        // Is array mein har element ek connected component ka size hoga.
        // Example: {3, 2, 4}
        vector<int> components;

        // Saare nodes check karo.
        for(int i = 0; i < n; i++) {

            // Sirf root nodes ko select karna hai.
            // Root node wahi hota hai jiska parent khud wohi node ho.
            if(parent[i] == i) {

                // size[i] mein current component ke total nodes hain.
                // Us size ko components array mein store kar do.
                components.push_back(size[i]);
            }
        }


        // STEP 4: Components array se unreachable pairs calculate karo.

        // Final answer store karne ke liye long long use kiya hai,
        // kyunki pairs ki total count int ki range se badi ho sakti hai.
        long long ans = 0;

        // Initially saare n nodes remaining hain.
        long long remaining = n;

        // Har connected component ko ek-ek karke process karo.
        for(int s : components) {

            // Current component mein s nodes hain.
            // Remaining nodes mein se current component ke s nodes hata do,
            // toh remaining - s nodes doosre components mein honge.
            //
            // Current component ka har node doosre components ke
            // har node ke saath unreachable pair banayega.
            //
            // Isliye total pairs = s * (remaining - s).
            ans += 1LL * s * (remaining - s);

            // Current component process ho chuka hai.
            // Ab uske nodes ko remaining count se remove kar do.
            //
            // Isse same pair dobara count nahi hoga.
            remaining -= s;
        }

        // Saare components process hone ke baad final answer return karo.
        return ans;
    }
};


/*
TIME COMPLEXITY:

1. DSU initialization:
   Parent aur size arrays initialize karne mein O(n).

2. Processing edges:
   Har edge par Union operation hota hai.
   Find uses path compression and Union uses size.
   Total = O(E * alpha(n)).

3. Components array:
   Saare n nodes traverse karte hain.
   Total = O(n).

4. Formula:
   Har connected component ko ek baar traverse karte hain.
   Maximum components n ho sakte hain.
   Total = O(n).

OVERALL TIME COMPLEXITY:
O(n + E * alpha(n))


SPACE COMPLEXITY:

1. Parent array = O(n)
2. Size array = O(n)
3. Components array = O(n)

OVERALL AUXILIARY SPACE:
O(n)
*/
