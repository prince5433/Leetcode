class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {

        int n = nums.size();
        int cnt = 0;

        // Pick first string
        for(int i = 0; i < n; i++){

            // Pick second string
            for(int j = 0; j < n; j++){

                // i != j ensures we are using different indices
                // Check if concatenation equals target
                if(i != j && nums[i] + nums[j] == target){
                    cnt++;
                }
            }
        }

        // Total valid pairs
        return cnt;
    }
};
