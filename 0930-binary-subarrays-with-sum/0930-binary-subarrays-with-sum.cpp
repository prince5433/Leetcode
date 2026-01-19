class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        vector<int> pre(n, 0);          // prefix sum array
        pre[0] = nums[0];               // first prefix sum

        for (int i = 1; i < n; i++) {
            pre[i] = nums[i] + pre[i - 1];   // pre[i] = sum of nums[0..i]
        }

        unordered_map<int, int> m;      // stores frequency of prefix sums
        int count = 0;                  // final answer

        for (int i = 0; i < n; i++) {

            if (pre[i] == goal) count++;     // subarray from 0..i has sum = goal

            int rem = pre[i] - goal;         // we need previous prefix sum = rem

            if (m.find(rem) != m.end())      // if rem exists, add its frequency
                count += m[rem];

            m[pre[i]]++;                     // store current prefix sum frequency
        }

        return count;
    }
};
