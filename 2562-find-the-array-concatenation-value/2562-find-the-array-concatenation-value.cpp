class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long sum = 0;          // stores final concatenation sum
        int l = 0;                  // left pointer
        int r = nums.size() - 1;    // right pointer

        while(l <= r) {
            // if only one element remains (odd length array)
            if(l == r) {
                sum += nums[l];     // add it once
                break;              // stop processing
            }

            // concatenate left and right numbers
            int c = stoi(to_string(nums[l]) + to_string(nums[r]));
            sum += c;               // add concatenated value

            l++;                    // move left pointer
            r--;                    // move right pointer
        }

        return sum;                 // return total sum
    }
};
