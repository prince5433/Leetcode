class Solution {
public:
    int minAllOneMultiple(int k) {

        int rem = 1 % k;   // "1" ka remainder jab k se divide karein
        int cone = 1;      // abhi number me 1 digit hai (sirf "1")

        unordered_set<int> st;
        st.insert(rem);    // pehla remainder store (cycle detect ke liye)

        while (true) {

            // agar remainder 0 aa gaya
            // matlab current number k se divisible hai
            if (rem == 0) return cone;

            // next number banate hain:
            // previous number * 10 + 1
            // remainder update karte hain bina number banaye
            rem = (rem * 10 + 1) % k;
            cone++;        // ek aur '1' add hua

            // agar remainder repeat ho gaya
            // matlab loop ban gaya, 0 kabhi nahi aayega
            if (st.count(rem)) {
                return -1;
            }

            st.insert(rem); // naye remainder ko set me daal do
        }
    }
};
