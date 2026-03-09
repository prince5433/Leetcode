class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {

        int n = nums.size();

        // prefix[i] → sum of elements strictly to the LEFT of index i
        vector<long long> prefix(n);

        // left side of index 0 is empty → sum = 0
        prefix[0] = 0;

        // Build prefix sum array
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }

        // suffix[i] → product of elements strictly to the RIGHT of index i
        vector<long long> suffix(n);

        // right side of last index is empty → product = 1
        suffix[n-1] = 1;

        // Build suffix product with overflow protection
        long long LIMIT = 1e15;

        for(int i = n-2; i >= 0; i--){

            // If multiplication may overflow, clamp value
            if(suffix[i+1] > LIMIT / nums[i+1]){
                suffix[i] = LIMIT;
            }
            else{
                suffix[i] = suffix[i+1] * nums[i+1];
            }
        }

        // Check each index if left sum == right product
        for(int i = 0; i < n; i++){

            if(prefix[i] == suffix[i]){
                return i;   // return smallest balanced index
            }
        }

        return -1;  // no balanced index exists
    }
};