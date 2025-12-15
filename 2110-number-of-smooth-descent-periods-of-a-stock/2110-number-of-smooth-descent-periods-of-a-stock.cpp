class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long cnt = 0;   // total number of descent periods
        int n = prices.size();
        long long len = 1;   // length of current descending sequence

        for (int i = 1; i < n; i++) {

            // If current price is exactly 1 less than previous
            if (prices[i] == prices[i - 1] - 1) {
                len++;   // extend the descending sequence
            } 
            else {
                // add subarrays formed by previous descending sequence
                cnt += (len * (len + 1)) / 2;
                len = 1; // reset for new sequence
            }
        }

        // add subarrays for the last descending sequence
        cnt += (len * (len + 1)) / 2;

        return cnt;
    }
};
