class Solution {
public:
    int minAllOneMultiple(int k) {

        // agar k 2 ya 5 se divisible hai → impossible
        // if (k % 2 == 0 || k % 5 == 0) return -1;

        int rem = 1 % k;
        int cone = 1;

        unordered_set<int> st;
        st.insert(rem);

        while (true) {

            if (rem == 0) return cone;   // divisible mil gaya

            rem = (rem * 10 + 1) % k;
            cone++;

            if (st.count(rem)) {        // cycle detect
                return -1;
            }

            st.insert(rem);             // naye remainder ko store karo
        }
    }
};
