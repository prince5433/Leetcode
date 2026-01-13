class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 0, hi = arr.size();      // binary search range [0, n]

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2; // mid index (safe, no overflow)

            // missing numbers till index mid
            // missing = arr[mid] - (mid + 1)
            if (arr[mid] - (mid + 1) >= k) {
                hi = mid;                 // answer mid ya left side me ho sakta hai
            } else {
                lo = mid + 1;             // answer right side me hoga
            }
        }

        // lo = first index jahan missing >= k
        // actual k-th missing number = lo + k
        return lo + k;
    }
};
