class Solution {
public:
    bool dfs(vector<int>& arr, vector<int>& vis, int n, int idx) {
        if (idx < 0 || idx >= n || vis[idx]) return false;

        if (arr[idx] == 0) return true;

        vis[idx] = 1;

        return dfs(arr, vis, n, idx + arr[idx]) ||
               dfs(arr, vis, n, idx - arr[idx]);
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);

        return dfs(arr, vis, n, start);
    }
};