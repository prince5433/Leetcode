class Solution {
public:
    /* =======================================================================
        🚀 PROBLEM: CLOSEST TARGET IN A CIRCULAR ARRAY
        =======================================================================
        💡 DEEP INTUITION:
        - Ek circular array mein hum aage (forward) aur peeche (backward) 
          dono taraf se ja sakte hain.
        - Shortest distance hamesha min(Direct distance, Wrap-around distance) hoga.
       =======================================================================
    */
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int mn = n; // Shuru mein max distance 'n' maan lo

        for (int i = 0; i < n; i++) {
            // 🔹 Step 1: Target dhoondo
            if (words[i] == target) {
                
                // 🔹 Step 2: Linear Distance calculate karo
                // abs() isliye taaki direction (+ ya -) se farak na pade
                int dist = abs(startIndex - i);
                
                // 🔹 Step 3: Circular (Wrap-around) Distance
                // Agar hum array ke end se jump marein
                int circular = (n - dist);
                
                // 🔹 Step 4: Dono rasto mein se minimum pick karo
                // Aur use 'mn' (overall minimum) ke saath update karo
                mn = min(mn, min(dist, circular));
            }
        }

        // 🔹 Final Check: Agar 'mn' update nahi hua, matlab target mila hi nahi
        if (mn == n) return -1;
        
        return mn;
    }
};