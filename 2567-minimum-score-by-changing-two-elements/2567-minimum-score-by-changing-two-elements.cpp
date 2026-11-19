
class Solution {
public:
    int minimizeSum(vector<int>& nums) {

        // Step 1: Calculate the size of the array
        int n = nums.size();

        // Step 2: If array has 3 or fewer elements,
        // we can change at most 2 elements and make
        // all elements equal.
        // Therefore, the minimum possible score is 0.
        if(n <= 3) return 0;

        // Step 3: Sort the array in ascending order.
        // After sorting:
        // nums[0]       = smallest element
        // nums[n-1]     = largest element
        // nums[1]       = second smallest
        // nums[n-2]     = second largest
        sort(nums.begin(), nums.end());

        // Step 4: Consider all possible ways of
        // removing the effect of two extreme elements.

        // OPTION 1:
        // Change the two smallest elements.
        // The new minimum will be nums[2].
        // The maximum remains nums[n-1].
        // Remaining range = largest - third smallest.
        int option1 = nums[n-1] - nums[2];

        // OPTION 2:
        // Change the two largest elements.
        // The minimum remains nums[0].
        // The new maximum will be nums[n-3].
        // Remaining range = third largest - smallest.
        int option2 = nums[n-3] - nums[0];

        // OPTION 3:
        // Change the smallest and the largest elements.
        // The new minimum becomes nums[1].
        // The new maximum becomes nums[n-2].
        // Remaining range = second largest - second smallest.
        int option3 = nums[n-2] - nums[1];

        // Step 5: Return the minimum range among
        // all three possible combinations.
        // Minimum difference can be made 0 by
        // changing two elements to the same value.
        return min({option1, option2, option3});
    }
};
