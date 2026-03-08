class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();   // total elements in the array (one number is missing)

        int x = 0;             // variable to store XOR result

        // Step 1: XOR all numbers from 0 to n
        for(int i = 0; i <= n; i++){
            x ^= i;
        }

        // Step 2: XOR all elements present in the array
        for(auto &i : nums){
            x ^= i;
        }

        // Explanation:
        // XOR property:
        // a ^ a = 0
        // a ^ 0 = a
        // XOR is commutative and associative

        // So all numbers that appear in both sequences cancel out
        // Only the missing number remains in x

        return x;   // this will be the missing number
    }
};