class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int i = 0;                // left pointer of sliding window
        int j = 0;                // right pointer of sliding window
        int n = nums.size();      // size of array

        int sum = 0;              // current window sum
        int maxsum = INT_MIN;     // maximum sum among all windows of size k

        // Sliding window traversal
        while (j < n) {

            // Add current element to window sum
            sum += nums[j];

            // Check if window size becomes exactly k
            if (j - i + 1 == k) {

                // Update maximum sum
                maxsum = max(maxsum, sum);

                // Slide the window:
                // remove leftmost element
                sum -= nums[i];
                i++;
            }

            // Move right pointer forward
            j++;
        }

        // Return maximum average
        return (double)maxsum / k;
    }
};
