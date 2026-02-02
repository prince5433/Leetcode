class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {

        int n = nums.size();                 // nums array ka size
        vector<int> ans(n, -1);              // answer array, default -1

        // Har element ke liye
        for(int i = 0; i < n; i++){

            // j ko 1 se nums[i] tak try kar rahe hain
            for(int j = 1; j <= nums[i]; j++){

                // Check: j OR (j+1) agar nums[i] ke equal ho
                // Brackets zaroori hain warna operator precedence galat ho jaayegi
                if ( (j | (j + 1)) == nums[i] ){

                    ans[i] = j;              // smallest j mil gaya
                    break;                  // aage check karne ki zarurat nahi
                }
            }
        }

        return ans;                          // final result return
    }
};
