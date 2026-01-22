class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();

        int maxidx = -1;   // max element ka index (original array me)
        int maxi = -1;     // max element ki value

        for(int i = 0; i < n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];   // new maximum update
                maxidx = i;       // uska index store
            }
        }

        sort(nums.begin(), nums.end());  // array sort kar diya (order change ho gaya)

        // sorted array me last element max hota hai
        // second last element second max hota hai
        // condition check: max >= 2 * secondMax
        if(nums[n-1] >= 2 * nums[n-2]) 
            return maxidx;   // original array ka index return kar rahe ho
        else 
            return -1;       // dominant nahi hai
    }
};
