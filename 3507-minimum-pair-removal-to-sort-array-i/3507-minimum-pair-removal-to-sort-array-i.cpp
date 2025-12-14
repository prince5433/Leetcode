class Solution {
public:
    // Check if array is non-decreasing (sorted)
    bool isSorted(vector<int>& nums){
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]) 
                return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        // Repeat until array becomes sorted
        while(!isSorted(nums)){

            int idx = 0;
            // Minimum sum of adjacent pair
            int mn = nums[0] + nums[1];

            // Find adjacent pair with minimum sum
            for(int i = 1; i < nums.size() - 1; i++){
                if(nums[i] + nums[i+1] < mn){
                    mn = nums[i] + nums[i+1];
                    idx = i;
                }
            }

            // Remove the selected pair
            // erase removes nums[idx]
            nums.erase(nums.begin() + idx);

            // Replace next element with their sum
            nums[idx] = mn;

            ops++; // one operation done
        }

        return ops;
    }
};
