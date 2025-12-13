class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();
        
        // Sort the array so we can pick medians greedily
        sort(nums.begin(), nums.end());
        
        long long sum = 0;
        
        // We need exactly n/3 medians.
        // Start from index (n-2) because the largest element
        // cannot be a median in any group of 3.
        // Each time, move left by 2 to skip the largest of the group.
        for (int i = n - 2; i >= (n / 3); i -= 2) {
            sum += nums[i];   // add the chosen median
        }
        
        // Return the maximum possible sum of medians
        return sum;
    }
};
