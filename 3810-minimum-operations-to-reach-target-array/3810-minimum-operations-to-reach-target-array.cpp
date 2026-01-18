class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        set<int> st;  // to store unique values from nums that are mismatching with target

        // traverse both arrays
        for(int i = 0; i < nums.size(); i++){
            
            // if nums[i] is not equal to target[i], this element needs to be changed
            // insert nums[i] into set so duplicates are counted only once
            if(nums[i] != target[i]) 
                st.insert(nums[i]);
        }

        // number of unique mismatching values = minimum operations required
        return st.size();
    }
};
