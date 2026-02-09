class Solution {
public:
    int maxSum(vector<int>& nums) {
        // find the maximum element in the array
        int maxi = *max_element(nums.begin(), nums.end());

        // if all numbers are negative, return the largest (least negative) number
        if(maxi < 0) return maxi;

        // use set to store unique elements
        set<int> st;
        for(int num : nums) 
            st.insert(num);

        int sum = 0;

        // add only non-negative unique elements
        for(int num : st){
            if(num >= 0){
                sum += num;
            }
        }

        // return the final sum
        return sum;
    }
};
