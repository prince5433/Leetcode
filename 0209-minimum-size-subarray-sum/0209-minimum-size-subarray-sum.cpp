class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        // i = window ka starting index (left pointer).
        // j = window ka ending index (right pointer).
        int i = 0;
        int j = 0;

        // Minimum valid subarray length store karega.
        // Initially INT_MAX rakha hai kyunki abhi koi valid
        // subarray nahi mila hai.
        int minlen = INT_MAX;

        // Current window ki length.
        int len = 0;

        // Current window ke elements ka sum.
        int sum = 0;

        // Right pointer se window ko expand karte rahenge.
        while (j < n) {

            // Current element ko window mein include karo.
            // Window expand hone ke saath sum increase hoga.
            sum += nums[j];

            // Jab tak current window ka sum target ke equal
            // ya greater hai, window valid hai.
            //
            // Humein minimum length chahiye, isliye valid window
            // milte hi left pointer se window shrink karenge.
            while (sum >= target) {

                // Current valid window ki length calculate karo.
                // Formula: ending index - starting index + 1.
                len = j - i + 1;

                // Ab tak ki minimum length ko update karo.
                minlen = min(minlen, len);

                // Leftmost element ko sum se remove karo,
                // kyunki ab hum window ko chhota kar rahe hain.
                sum -= nums[i];

                // Window ka starting point ek position aage badhao.
                i++;
            }

            // Current window process ho gayi.
            // Ab next element ko include karne ke liye right pointer badhao.
            j++;
        }

        // Agar minlen abhi bhi INT_MAX hai,
        // iska matlab koi valid subarray nahi mila.
        if (minlen == INT_MAX) {
            return 0;
        }

        // Minimum valid subarray length return karo.
        return minlen;
    }
};

/*
TIME COMPLEXITY: O(N)
Har element maximum ek baar window mein add aur
maximum ek baar window se remove hota hai.

SPACE COMPLEXITY: O(1)
Sirf constant extra variables use ho rahe hain.
*/