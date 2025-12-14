class Solution {
public:
    int absDifference(vector<int>& nums, int k) {

        // Sort in ascending order
        sort(nums.begin(), nums.end());

        // Sum of k smallest elements
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }

        // Sort in descending order
        sort(nums.rbegin(), nums.rend());

        // Sum of k largest elements
        int sum1 = 0;
        for(int i = 0; i < k; i++){
            sum1 += nums[i];
        }

        // Absolute difference
        return abs(sum - sum1);
    }
};
