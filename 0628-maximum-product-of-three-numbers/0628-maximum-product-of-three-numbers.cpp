class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end()); 
        // sorting ke baad:
        // nums[0], nums[1] -> 2 smallest (most negative ho sakte hain)
        // nums[n-1], nums[n-2], nums[n-3] -> 3 largest numbers

        return max(
            nums[n-1] * nums[n-2] * nums[n-3],  // case 1: 3 largest ka product
            nums[n-1] * nums[0] * nums[1]       // case 2: largest * 2 smallest (negative*negative = positive)
        );
    }
};
