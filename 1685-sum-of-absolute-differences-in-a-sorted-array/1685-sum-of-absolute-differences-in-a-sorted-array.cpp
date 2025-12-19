class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {

        int n = nums.size();          // size of array
        vector<int> ans(n);           // answer array

        int ts = 0;                   // ts = total sum of array
        for(int x : nums) 
            ts += x;

        int leftsum = 0;              // sum of elements on left side

        for(int i = 0; i < n; i++) {

            // LEFT PART:
            // nums[i] se left ke sab elements ka difference
            // formula: i * nums[i] - leftsum
            int left = (i * nums[i]) - leftsum;

            // RIGHT PART:
            // nums[i] se right ke sab elements ka difference
            // formula: (sum of right elements) - (count * nums[i])
            int right = (ts - leftsum - nums[i]) 
                        - (n - i - 1) * nums[i];

            // total absolute difference for index i
            ans[i] = left + right;

            // update leftsum for next iteration
            leftsum += nums[i];
        }

        return ans;
    }
};
