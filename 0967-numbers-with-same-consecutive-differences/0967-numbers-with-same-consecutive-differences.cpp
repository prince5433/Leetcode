class Solution {
public:

    // DFS to build numbers digit by digit
    void dfs(vector<int>& ans, int n, int k, int len, int num) {

        // Base case: if we already formed an n-digit number → store it
        if (len == n) {
            ans.push_back(num);
            return;
        }

        // Get the last digit of the current number
        int last = num % 10;

        // Two possible next digits: last + k and last - k
        int next = last + k;
        int prev = last - k;

        // Try adding (last + k) if it's a valid digit (0–9)
        if (next <= 9) {
            // Extend the number by adding next digit at the end
            dfs(ans, n, k, len + 1, num * 10 + next);
        }

        // Try adding (last - k) only if k != 0 (to avoid duplicates) and valid digit
        if (k != 0 && prev >= 0) {
            dfs(ans, n, k, len + 1, num * 10 + prev);
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;

        // Start the number from digits 1 to 9 (leading zeros not allowed)
        for (int i = 1; i <= 9; i++) {
            dfs(ans, n, k, 1, i);   // starting length = 1, number = i
        }

        return ans;
    }
};
