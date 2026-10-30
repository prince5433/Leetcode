class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();

        // nge[i] store karega ki temperatures[i] se kitne days
        // baad pehli strictly warmer temperature milegi.
        // Agar koi warmer day nahi mila, toh answer 0 hoga.
        vector<int> nge(n);

        // Stack mein un indices ko store karenge
        // jinke liye future warmer temperature mil sakta hai.
        stack<int> st;

        // Last day ke baad koi future day available nahi hai.
        // Isliye last index ka answer hamesha 0 hoga.
        nge[n - 1] = 0;

        // Last index ko stack mein daalo.
        // Ye previous days ke liye possible warmer day ho sakta hai.
        st.push(n - 1);

        // Right se left traverse karenge,
        // taaki current day ke right side ke temperatures stack mein hon.
        for (int i = n - 2; i >= 0; i--) {

            // Jab tak stack empty nahi hai aur top index ka temperature
            // current temperature se chhota ya equal hai,
            // us index ko remove kar do.
            //
            // WHY?
            // Humein strictly warmer temperature chahiye.
            // Current temperature se chhote ya equal temperatures
            // is day ke answer nahi ho sakte.
            while (st.size() > 0 &&
                   temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // Agar stack empty ho gaya, toh current day ke baad
            // koi strictly warmer temperature available nahi hai.
            if (st.size() == 0) {
                nge[i] = 0;
            }

            // Stack ke top par ab nearest strictly warmer day ka index hai.
            // Index difference se pata chalega kitne days wait karna hai.
            else {
                nge[i] = st.top() - i;
            }

            // Current index ko stack mein add karo,
            // taaki ye bhi isse pehle wale days ke liye
            // possible warmer temperature ban sake.
            st.push(i);
        }

        // Har day ke waiting days ka answer return karo.
        return nge;
    }
};

/*
TIME COMPLEXITY: O(N)
Har index stack mein exactly ek baar push aur maximum ek baar pop hota hai.

SPACE COMPLEXITY: O(N)
NGE array aur monotonic stack dono O(N) space lete hain.
*/