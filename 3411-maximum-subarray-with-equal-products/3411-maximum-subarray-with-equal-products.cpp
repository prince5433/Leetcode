class Solution {
public:
    bool isProductEquivalent(vector<int>& nums, int i, int j) {
        long long int product = 1;
        long long int g = 0;
        long long int l = 1;

        for (int k = i; k <= j; k++) {
            long long int x = nums[k];

            // Multiplication se pehle overflow check
            if (product > LLONG_MAX / x) {
                return false;
            }

            product *= x;

            g = gcd(g, x);
            l = l / gcd(l, x) * x;
        }

        return product == g * l;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isProductEquivalent(nums, i, j)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};