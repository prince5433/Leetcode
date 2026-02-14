class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {

        // ans stores total hamming distance of all pairs
        int ans = 0;

        // n = size of array
        int n = nums.size();

        // Outer loop → pick first number of pair
        for(int i = 0; i < n; i++){

            // Inner loop → pick second number of pair
            // starts from i to avoid repeating same pairs
            for(int j = i; j < n; j++){

                // Skip same index because distance with itself = 0
                if(i != j){

                    // nums[i] ^ nums[j]
                    // XOR gives bits where both numbers differ

                    // __builtin_popcount counts number of set bits (1s)
                    // which equals hamming distance between nums[i] and nums[j]
                    ans += __builtin_popcount(nums[i] ^ nums[j]);
                }
            }
        }

        // Return total hamming distance of all pairs
        return ans;
    }
};
