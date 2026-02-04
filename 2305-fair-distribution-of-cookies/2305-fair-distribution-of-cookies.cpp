class Solution {
public:
    int ans = INT_MAX;   // final answer: minimum unfairness
    int n;               // total number of cookies

    void solve(int idx, vector<int>& child, vector<int>& cookies, int k) {

        // Base case:
        // Agar saari cookies distribute ho chuki hain
        if (idx == n) {

            // Har child ke paas maximum cookies nikal rahe hain
            int maxi = *max_element(child.begin(), child.end());

            // Answer update
            ans = min(ans, maxi);
            return;
        }

        int cookie = cookies[idx];  // current cookie packet

        // Current cookie ko har child ko dene ka try
        for (int i = 0; i < k; i++) {

            // TAKE:
            // cookie i-th child ko de di
            child[i] += cookie;

            // Next cookie ke liye recursion
            solve(idx + 1, child, cookies, k);

            // BACKTRACK:
            // cookie wapas le li
            child[i] -= cookie;
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {

        n = cookies.size();

        // child[i] = i-th child ke paas kitni cookies hain
        vector<int> child(k, 0);

        // Backtracking start
        solve(0, child, cookies, k);

        return ans;
    }
};
