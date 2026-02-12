class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int n = nums.size();
        int ans = INT_MAX;

        // fix starting index
        for(int i = 0; i < n; i++){

            int sum = 0;

            // fix ending index
            for(int j = i; j < n; j++){

                sum += nums[j];

                int len = j - i + 1;

                // check length condition
                if(len >= l && len <= r){

                    // check positive sum
                    if(sum > 0){
                        ans = min(ans, sum);
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
