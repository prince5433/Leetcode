class Solution {
public:

    vector<int> remainingMethods(int n,
                                 int k,
                                 vector<vector<int>>& invocations) {

        // Adjacency List
        //
        // adj[u] = Saare methods
        // jo method u call karta hai.
        vector<vector<int>> adj(n);

        // inDegree[i]
        //
        // Method i ko
        // kitne methods call karte hain.
        vector<int> inDegree(n, 0);

        // suspicious[i]
        //
        // true  -> Suspicious Method
        // false -> Safe Method
        vector<bool> suspicious(n, false);

        // Graph banao.
        for (auto &edge : invocations) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);

            // Incoming edge count.
            inDegree[v]++;
        }

        // ---------------- BFS ----------------
        //
        // WHY BFS?
        //
        // Agar koi method suspicious hai,
        // to uske through call hone wale
        // saare methods bhi suspicious ban jayenge.
        //
        // Isliye k se traversal karenge.
        queue<int> qu;

        qu.push(k);

        // Starting suspicious method.
        suspicious[k] = true;

        while (!qu.empty()) {

            int curr = qu.front();
            qu.pop();

            // Current method ke
            // saare invoked methods check karo.
            for (auto &ngbr : adj[curr]) {

                // WHY indegree decrease?
                //
                // Hum suspicious graph ko
                // remove karne ki simulation kar rahe hain.
                //
                // Current edge remove ho gayi.
                inDegree[ngbr]--;

                // Agar neighbour pehle visit nahi hua.
                if (!suspicious[ngbr]) {

                    suspicious[ngbr] = true;

                    qu.push(ngbr);
                }
            }
        }

        // Final answer.
        vector<int> result;

        // Agar suspicious component ko
        // remove nahi kar sakte,
        // to ye true ho jayega.
        bool cannotRemove = false;

        for (int i = 0; i < n; i++) {

            // WHY ye condition?
            //
            // Agar koi suspicious method
            // ke paas abhi bhi
            // incoming edge bachi hui hai,
            //
            // to matlab koi non-suspicious method
            // usse call kar raha hai.
            //
            // Is situation me
            // suspicious methods ko
            // remove nahi kar sakte.
            if (suspicious[i] && inDegree[i] > 0) {

                cannotRemove = true;

                break;
            }

            // Safe methods answer me add karo.
            if (!suspicious[i]) {

                result.push_back(i);
            }
        }

        // Agar remove nahi kar sakte,
        // to saare methods return karo.
        if (cannotRemove) {

            vector<int> vec(n);

            for (int i = 0; i < n; i++) {

                vec[i] = i;
            }

            return vec;
        }

        return result;
    }
};

/*
---------------- INTUITION ----------------

Question bolta hai

Method k

suspicious hai.

Agar koi suspicious method
kisi aur method ko call karta hai,

to wo method bhi suspicious ban jayega.

Isliye

k

se BFS chalayenge.

Aur jitne methods reachable honge,

sab suspicious mark ho jayenge.

---------------- Example ----------------

0 → 1 → 2

↓

3

Suppose

k = 1

Traversal

1

↓

2

Methods

1

2

Suspicious

Safe

0

3

---------------- WHY indegree decrease? ----------------

Hum imagine kar rahe hain ki

Suspicious methods

remove kar diye.

Agar kisi suspicious method ke paas

ab bhi incoming edge bachi hui hai,

to matlab

koi safe method

abhi bhi usse call kar raha hai.

Aise case me

remove karna allowed nahi.

---------------- Example ----------------

0 → 1

k = 1

1 suspicious hai.

Lekin

0

abhi bhi

1

ko call kar raha hai.

To

1

remove nahi kar sakte.

Answer

Saare methods.

---------------- Time Complexity ----------------

Building Graph

O(E)

BFS

Har vertex ek baar.

Har edge ek baar.

O(V + E)

Final Traversal

O(V)

Overall

TC = O(V + E)

where,

V = Number of Methods

E = Number of Invocations

---------------- Space Complexity ----------------

Adjacency List

O(V + E)

Visited (Suspicious)

O(V)

Queue

Worst Case

O(V)

Result

O(V)

Overall SC

O(V + E)
*/