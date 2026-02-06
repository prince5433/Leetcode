class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {

        int n = nums.size();          // array ka size
        sort(nums.begin(), nums.end()); // array ko sort kar rahe hain

        int ans = n;                  // worst case: saare elements remove karne padenge
        int i = 0;                    // left pointer (window ka minimum)
        int j = 0;                    // right pointer (window ka maximum)

        // Sliding window start
        while (j < n) {

            // Jab tak window invalid hai
            // condition: max > k * min
            while (nums[j] > (long long)k * nums[i]) {
                i++;                 // minimum ko aage badha rahe hain
            }

            // Ab window valid hai
            // window size = j - i + 1
            // removals = total elements - window size
            ans = min(ans, n - (j - i + 1));

            // window ko right side se expand kar rahe hain
            j++;
        }

        // Minimum removals return
        return ans;
    }
};
