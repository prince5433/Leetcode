class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;   // total number of centered subarrays

        // choose starting index of subarray
        for (int i = 0; i < n; i++) {
            int sum = 0;                 // sum of current subarray
            unordered_set<int> st;       // elements present in current subarray

            // extend subarray from i to j
            for (int j = i; j < n; j++) {
                sum += nums[j];          // update sum
                st.insert(nums[j]);      // insert current element

                // if subarray sum exists inside the same subarray
                // then this subarray is centered
                if (st.count(sum))
                    ans++;
            }
        }
        return ans;   // return final count
    }
};
