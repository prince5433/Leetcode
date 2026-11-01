// Time Complexity: O(n * n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        /*
        INTUITION (Bottom-Up DP):

        Instead of recursion, we build the answer iteratively.

        dp[i] represents:
        Length of the Longest Increasing Subsequence
        that ends exactly at index i.

        Initially every element itself forms a subsequence
        of length 1.
        */

        vector<int> dp(n, 1);

        /*
        For each element i,
        check all previous elements j < i.

        If nums[j] < nums[i],
        we can extend the LIS ending at j.
        */

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < i; j++) {

                if(nums[j] < nums[i]) {

                    // Extend subsequence ending at j
                    dp[i] = max(dp[i], dp[j] + 1);

                }
            }
        }

        /*
        The answer is the maximum LIS length
        among all ending positions.
        */

       return *max_element(dp.begin(),dp.end());
    }
};