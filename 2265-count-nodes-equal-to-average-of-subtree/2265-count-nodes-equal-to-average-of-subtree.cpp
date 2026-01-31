class Solution {
public:
    int ans = 0;

    // DFS function returns {sum of subtree, count of nodes in subtree}
    pair<int,int> dfs(TreeNode* root) {
        // base case
        if (!root) return {0, 0};

        // postorder traversal
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // total sum of subtree
        int totalSum = left.first + right.first + root->val;

        // total node count of subtree
        int totalCount = left.second + right.second + 1;

        // average check
        if (totalSum / totalCount == root->val)
            ans++;

        // parent ko sum & count return karo
        return {totalSum, totalCount};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
