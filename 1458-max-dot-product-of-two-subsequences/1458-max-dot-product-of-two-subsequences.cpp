class Solution {
public:

    int n, m;                     // sizes of both arrays
    int dp[501][501];             // memoization table

    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j){

        // base case: agar kisi array ka end aa gaya
        // to valid pair possible nahi hai
        if(i == n || j == m) 
            return -1e9;

        // agar already calculate ho chuka hai
        if(dp[i][j] != -1) 
            return dp[i][j];

        // current pair ka dot product
        int product = nums1[i] * nums2[j];

        // case 1: dono elements pick karo
        int take_both = product + solve(nums1, nums2, i+1, j+1);

        // case 2: nums1[i] skip karo
        int take_i = solve(nums1, nums2, i, j+1);

        // case 3: nums2[j] skip karo
        int take_j = solve(nums1, nums2, i+1, j);

        // maximum choose karte hain
        return dp[i][j] = max({product, take_both, take_i, take_j});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        memset(dp, -1, sizeof(dp));   // dp initialize

        n = nums1.size();
        m = nums2.size();

        // recursion start from index 0
        return solve(nums1, nums2, 0, 0);
    }
};