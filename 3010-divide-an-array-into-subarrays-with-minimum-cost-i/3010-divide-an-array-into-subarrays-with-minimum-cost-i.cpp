class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int mini = INT_MAX;   // nums[1..] me smallest value
        int smin = INT_MAX;   // nums[1..] me second smallest value
        int idx = -1;         // mini ka index store karenge

        // step 1: nums[0] ko chhod ke minimum element nikalna
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < mini){
                mini = nums[i];   // update minimum
                idx = i;          // minimum ka index store
            }
        }

        // step 2: second minimum nikalna (mini wale index ko skip karke)
        for(int i = 1; i < nums.size(); i++){
            if(i == idx) continue;    // same index repeat nahi karna
            if(nums[i] < smin){
                smin = nums[i];       // update second minimum (duplicate allowed)
            }
        }

        // final cost = nums[0] + two smallest from remaining elements
        return nums[0] + mini + smin;
    }
};
