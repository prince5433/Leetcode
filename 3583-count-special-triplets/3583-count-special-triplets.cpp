class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        const long long MOD = 1e9 + 7;

        // left[x]  = how many times value x has appeared BEFORE current index
        // right[x] = how many times value x will appear AFTER current index
        unordered_map<long long, long long> left, right;

        // Initially, all elements are considered on the "right" side
        for (int x : nums) right[x]++;

        long long ans = 0;

        // Iterate each element and treat it as the middle element nums[j]
        for (int x : nums) {
            right[x]--;                // x is no longer on the right side → now acting as middle

            long long tgt = 2LL * x;   // nums[i] and nums[k] must be 2 * nums[j]

            // left[tgt]  = how many nums[i] = 2*x exist on the left side (i < j)
            // right[tgt] = how many nums[k] = 2*x exist on the right side (j < k)
            // Multiply both counts → all valid pairs (i, j, k) with this j
            ans = (ans + (left[tgt] * right[tgt]) % MOD) % MOD;

            left[x]++;                 // x now becomes part of the left section for future iterations
        }

        // Final result modulo 1e9+7
        return ans % MOD;
    }
};
