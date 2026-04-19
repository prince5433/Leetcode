class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        
        // Sort the array to get the maximum element at the end
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        // The largest element in the array
        int val = nums[n - 1];
        
        /*
        Each time we pick the largest element, we increment it by 1
        So sequence becomes:
        val, val+1, val+2, ..., val+(k-1)
        
        Sum of this sequence:
        = k * val + (0 + 1 + 2 + ... + (k-1))
        = k * val + (k*(k-1))/2
        */
        
        return (val * k) + (k * (k - 1)) / 2;
    }
};