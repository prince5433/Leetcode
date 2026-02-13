class Solution {
public:

int rob(vector<int>& nums) {

    int n = nums.size();

    // Corner case:
    // If only one house
    if(n == 1)
        return nums[0];

    // dp[i] = maximum money that can be robbed starting from index i
    vector<int> dp(n);

    // Base case:
    // Last house → only option is to rob it
    dp[n-1] = nums[n-1];

    // Second last house → choose max of last or second last
    dp[n-2] = max(nums[n-2], nums[n-1]);

    // Fill dp array from right to left
    for(int i = n-3; i >= 0; i--){

        // Choice 1: Skip current house
        int skip = dp[i+1];

        // Choice 2: Rob current house
        int rob = nums[i] + dp[i+2];

        // Store maximum
        dp[i] = max(skip, rob);
    }

    // dp[0] contains final answer
    return dp[0];
}
};
