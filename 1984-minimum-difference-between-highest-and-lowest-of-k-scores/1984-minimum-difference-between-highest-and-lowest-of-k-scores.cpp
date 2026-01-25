class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());          // sort so that close elements stay near each other

        int n = nums.size();
        int mini = INT_MAX;                      // store minimum difference answer

        int i = 0, j = 0;                        // sliding window pointers

        while (j < n) {
            if (j - i + 1 == k) {                // when window size becomes exactly k
                mini = min(mini, nums[j] - nums[i]); // max-min inside window (sorted => nums[j] is max, nums[i] is min)
                i++;                             // slide window forward from left
            }
            j++;                                 // always expand window by moving right
        }

        return mini;                             // minimum possible difference
    }
};
