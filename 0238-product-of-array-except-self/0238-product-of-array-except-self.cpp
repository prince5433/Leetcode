class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        
        // leftPro[i] will store product of all elements before index i
        vector<int> leftPro(n, 1);
        
        // rightPro[i] will store product of all elements after index i
        vector<int> rightPro(n, 1);

        // ---------------------------
        // Step 1: Build left product array
        // ---------------------------
        // leftPro[i] = leftPro[i-1] * nums[i-1]
        // means product of elements before i
        
        for(int i = 1; i < n; i++){
            leftPro[i] = leftPro[i-1] * nums[i-1];
        }

        // ---------------------------
        // Step 2: Build right product array
        // ---------------------------
        // rightPro[i] = rightPro[i+1] * nums[i+1]
        // means product of elements after i
        
        for(int i = n-2; i >= 0; i--){
            rightPro[i] = rightPro[i+1] * nums[i+1];
        }

        // ---------------------------
        // Step 3: Multiply left and right
        // ---------------------------
        // Final answer at index i:
        // product of all except self
        // = leftPro[i] * rightPro[i]
        
        for(int i = 0; i < n; i++){
            nums[i] = leftPro[i] * rightPro[i];
        }

        return nums;
    }
};