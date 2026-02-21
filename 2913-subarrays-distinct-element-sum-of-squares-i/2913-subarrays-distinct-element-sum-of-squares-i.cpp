class Solution {
public:
    int sumCounts(vector<int>& nums) {
        
        // size of array
        int n = nums.size();
        
        // variable to store final answer
        int cnt = 0;
        
        // outer loop fixes the starting index of subarray
        for(int i = 0; i < n; i++){
            
            // unordered_set to store distinct elements of current subarray
            unordered_set<int> st;
            
            // inner loop extends subarray from index i to n-1
            for(int j = i; j < n; j++){
                
                // insert current element into set
                // set automatically keeps only distinct elements
                st.insert(nums[j]);
                
                // number of distinct elements in current subarray
                int distinctCount = st.size();
                
                // add square of distinct count to result
                cnt += distinctCount * distinctCount;
            }
        }
        
        // return final sum
        return cnt;
    }
};