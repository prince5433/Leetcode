class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        // Prefix sum array
        vector<int> pre(n, 0);

        // First prefix element
        pre[0] = nums[0];

        // Build prefix sum
        for(int i = 1; i < n; i++){
            pre[i] = nums[i] + pre[i-1];
        }

        // Map to store frequency of prefix sums
        unordered_map<int,int> m;

        int count = 0;

        for(int i = 0; i < n; i++) {

            // If prefix itself equals k
            if(pre[i] == k)
                count++;

            // We want: pre[i] - pre[j] = k
            // So, pre[j] = pre[i] - k
            int rem = pre[i] - k;

            // If such prefix exists before
            if(m.find(rem) != m.end())
                count += m[rem];

            // Store current prefix sum
            m[pre[i]]++;
        }

        return count;
    }
};