class Solution {
public:
   int dp[100005][2][2];

int f(vector<int>& prices, int i, int k, bool on) {
    if (i == prices.size() || k == 0) return 0;
    if (dp[i][k][on] != -1) return dp[i][k][on];

    int ans = f(prices, i + 1, k, on);
    if (on) {
        ans = max(ans, prices[i] + f(prices, i + 1, k - 1, false));
    } else {
        ans = max(ans, f(prices, i + 1, k, true) - prices[i]);
    }

    return dp[i][k][on] = ans;
}

int maxProfit(vector<int>& prices) {
    memset(dp, -1, sizeof(dp));
    return f(prices, 0, 1, false);
}

};