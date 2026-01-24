class Solution {
public:
    int minPairSum(vector<int>& nums) {

        // Step 1: Sort the array so that smallest and largest elements are aligned properly
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // maxi will store the maximum pair sum among all formed pairs
        int maxi = INT_MIN;

        // Step 2: Pair smallest with largest, 2nd smallest with 2nd largest, etc.
        for (int i = 0; i < n / 2; i++) {

            // Current pair sum = nums[i] (small) + nums[n-i-1] (large)
            int currsum = nums[i] + nums[n - i - 1];

            // Track the maximum pair sum, because we want to minimize this maximum
            maxi = max(maxi, currsum);
        }

        // Step 3: Return the minimized maximum pair sum
        return maxi;
    }
};
