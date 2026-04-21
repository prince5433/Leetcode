class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n - 1;

        // Binary search on rotated sorted array with duplicates
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            // If mid element matches target → found
            if (nums[mid] == target) return true;

            // Edge case: duplicates at lo, mid, hi
            // We cannot decide which half is sorted
            // So shrink search space from both ends
            if (nums[lo] == nums[mid] && nums[mid] == nums[hi]) {
                lo++;
                hi--;
            }

            // Left half [lo → mid] is sorted
            else if (nums[lo] <= nums[mid]) {

                // Check if target lies in this sorted half
                if (nums[lo] <= target && target <= nums[mid]) {
                    // Search in left half
                    hi = mid - 1;
                } else {
                    // Otherwise, search in right half
                    lo = mid + 1;
                }
            }

            // Right half [mid → hi] is sorted
            else {

                // Check if target lies in this sorted half
                if (nums[mid] <= target && target <= nums[hi]) {
                    // Search in right half
                    lo = mid + 1;
                } else {
                    // Otherwise, search in left half
                    hi = mid - 1;
                }
            }
        }

        // Target not found
        return false;
    }
};