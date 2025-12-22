class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {

        int odd = 1, even = 0;   // odd → index for odd numbers (1,3,5...)
                                 // even → index for even numbers (0,2,4...)

        int n = nums.size();     // size of input array

        vector<int> ans(n, -1);  // result array of same size, initialized with -1

        // Traverse each number in the input array
        for (int num : nums) {

            // If number is even
            if (num % 2 == 0) {
                ans[even] = num; // place even number at even index
                even += 2;       // move to next even index
            }
            // If number is odd
            else {
                ans[odd] = num;  // place odd number at odd index
                odd += 2;        // move to next odd index
            }
        }

        return ans;  // return the rearranged array
    }
};
