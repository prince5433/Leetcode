class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());      // sort to apply sliding window
        int n = nums.size();
        int l = 0;
        int ans = 0;                         // minimum XOR is 0 (x ^ x)

        for(int r = 0; r < n; r++){
            // shrink window until strong pair condition holds
            while(nums[r] > 2 * nums[l]) 
                l++;

            // all pairs (i, r) where l <= i <= r are strong pairs
            for(int i = l; i <= r; i++){
                ans = max(ans, nums[i] ^ nums[r]);
            }
        }
        return ans;
    }
};
