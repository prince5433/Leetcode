class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size();          // total numbers in array

        vector<string> ans;           // har number ko string form me store karenge
        for (int i = 0; i < n; i++) {
            ans.push_back(to_string(nums[i]));  // number → string
        }

        int cnt = 0;                  // beautiful pairs ka count

        // har pair (i, j) ke liye check
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {

                int a = ans[i][0] - '0';      // nums[i] ka first digit
                int b = ans[j].back() - '0';  // nums[j] ka last digit

                // agar gcd(first digit, last digit) == 1
                // to ye ek beautiful pair hai
                if (__gcd(a, b) == 1)
                    cnt++;
            }
        }

        return cnt;                   // total beautiful pairs
    }
};
