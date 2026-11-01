class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();

        int i = 0;       // Left pointer: window ka starting index
        int j = 0;       // Right pointer: window ka ending index

        int flips = 0;   // Current window mein flipped zeros ki count
        int maxlen = 0;  // Maximum valid window length

        // Right pointer se window ko expand karenge.
        while (j < n) {

            // CASE 1: Current element zero hai.
            // Zero ko 1 banane ke liye ek flip use karna padega.
            if (nums[j] == 0) {
                flips++;
            }

            // CASE 2: Agar flips k se zyada ho gaye,
            // toh current window invalid ho gayi.
            // Humein left side se window shrink karni padegi.
            while (flips > k) {

                // Agar leftmost element zero hai,
                // toh us zero ko window se remove kar rahe hain.
                // Isliye uska flip bhi restore karna padega.
                if (nums[i] == 0) {
                    flips--;
                }

                // Left pointer aage badhakar window shrink karo.
                i++;
            }

            // Ab window valid hai (flips <= k).
            // Current window ki length calculate karke answer update karo.
            maxlen = max(maxlen, j - i + 1);

            // Right pointer aage badhakar next element include karo.
            j++;
        }

        return maxlen;
    }
};

/*
TC: O(N) — Dono pointers maximum N times move karte hain.
SC: O(1) — Constant extra space.
*/