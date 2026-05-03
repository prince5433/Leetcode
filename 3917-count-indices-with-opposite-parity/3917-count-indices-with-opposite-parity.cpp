class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();

        // answer array where ans[i] = count of opposite parity elements after i
        vector<int> ans(n, 0);

        // traverse each element one by one
        for(int i = 0; i < n; i++) {

            int cnt = 0;   // count for current index i

            // check all elements to the right of i
            for(int j = i + 1; j < n; j++) {

                // if current element is even
                if(nums[i] % 2 == 0) {

                    // count odd elements on right side
                    if(nums[j] % 2 == 1) cnt++;

                } else {

                    // if current element is odd,
                    // count even elements on right side
                    if(nums[j] % 2 == 0) cnt++;
                }
            }

            // store result for current index
            ans[i] = cnt;
        }

        return ans;
    }
};