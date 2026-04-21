class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        // pmax[i] → maximum element from index 0 to i (prefix max)
        vector<int> pmax(n);

        // pmin[i] → minimum element from index i to n-1 (suffix min)
        vector<int> pmin(n);

        // Initialize base cases
        pmax[0] = nums[0];
        pmin[n - 1] = nums[n - 1];

        // Build prefix max array
        // Intuition:
        // At every index i, we store the maximum value seen so far from the left
        for (int i = 1; i < n; i++) {
            pmax[i] = max(pmax[i - 1], nums[i]);
        }

        // Build suffix min array
        // Intuition:
        // At every index i, we store the minimum value from i to the end
        for (int i = n - 2; i >= 0; i--) {
            pmin[i] = min(pmin[i + 1], nums[i]);
        }

        // Now check each index
        // Intuition:
        // For index i to be "stable":
        // max(left side including i) - min(right side including i) <= k
        // i.e., pmax[i] - pmin[i] <= k
        for (int i = 0; i < n; i++) {
            if (pmax[i] - pmin[i] <= k) {
                return i; // first valid index
            }
        }

        // If no such index exists
        return -1;
    }
};