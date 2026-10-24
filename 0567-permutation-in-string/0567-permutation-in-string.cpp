
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        // INTUITION: s1 ki permutation ka length n hi hoga.
        // Agar s2 chhota hai, toh usmein n-length substring possible nahi.
        if (n > m) return false;

        // INTUITION: Har lowercase letter ki frequency store karenge.
        // Permutation mein order change ho sakta hai, par frequencies same honi chahiye.
        vector<char> as1(26, 0);
        vector<char> as2(26, 0);

        // s1 ke har character ki required frequency count karo.
        for (char c : s1) {
            as1[c - 'a']++;
        }

        int i = 0; // Sliding window ka starting index.
        int j = 0; // Sliding window ka ending index.

        // INTUITION: s2 mein fixed-size window of length n search karni hai.
        // Har step par right pointer j se ek naya character add hoga.
        while (j < m) {
            as2[s2[j] - 'a']++; // Right wala character window mein add karo.

            // INTUITION: Window size n se bada ho gaya toh
            // leftmost character remove karke size wapas n karo.
            if (j - i + 1 > n) {
                as2[s2[i] - 'a']--; // Left character ki frequency ghatao.
                i++;                // Window ko ek position right shift karo.
            }

            // INTUITION: Size n hone par hi comparison meaningful hai.
            // Agar frequencies match hain, current window s1 ki permutation hai.
            if (j - i + 1 == n && as1 == as2) {
                return true;
            }

            j++; // Agli window banane ke liye right pointer aage badhao.
        }

        // Koi bhi window s1 ki permutation nahi bani.
        return false;
    }
};

/*
TC: O(N + M), where N = s1.length() and M = s2.length().
    Dono frequency arrays fixed size 26 hain, isliye comparison O(1) hai.

SC: O(1), because frequency arrays each contain only 26 elements.
*/
