class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // Har index ko 1-based indexing se check karenge.
        for (int i = 1; i <= n; i++) {

            // Agar i, n ko completely divide karta hai,
            // toh i ek special index hai.
            if (n % i == 0) {

                // C++ indexing 0-based hoti hai,
                // isliye i-th element ke liye nums[i-1] use karenge.
                // Special element ka square answer mein add karo.
                ans += nums[i - 1] * nums[i - 1];
            }
        }

        // Sabhi special elements ke squares ka sum return karo.
        return ans;
    }
};