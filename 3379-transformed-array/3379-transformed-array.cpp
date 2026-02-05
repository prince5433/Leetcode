class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        for(int i = 0; i < n; i++) {

            // Case 1: positive value → RIGHT movement
            if(nums[i] > 0) {
                int idx = (i + nums[i]) % n;
                result[i] = nums[idx];
            }

            // Case 2: negative value → LEFT movement
            else if(nums[i] < 0) {
                int idx = (i + nums[i]) % n;  // left move
                if(idx < 0) idx += n;         // negative index fix
                result[i] = nums[idx];
            }

            // Case 3: zero → same index
            else {
                result[i] = nums[i];
            }
        }

        return result;
    }
};
