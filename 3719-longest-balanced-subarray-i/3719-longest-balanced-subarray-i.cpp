class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();   // total number of elements
        int ans = 0;           // stores maximum balanced subarray length

        // fix starting index of subarray
        for(int i = 0; i < n; i++){
            
            // sets to store unique even and odd numbers
            unordered_set<int> even, odd;

            // extend subarray from i to j
            for(int j = i; j < n; j++){
                
                // check if current number is even
                if(nums[j] % 2 == 0) 
                    even.insert(nums[j]); // store in even set
                else 
                    odd.insert(nums[j]);  // store in odd set

                // if number of unique evens equals unique odds
                if(even.size() == odd.size()){
                    // update maximum length
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans; // return final answer
    }
};
