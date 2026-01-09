/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root) 
            return {NULL, 0};  // empty node → depth 0, no LCA

        // 🔹 Recursive DFS on left and right subtrees
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // 🔹 Case 1: left and right deepest leaves have same depth
        // Current node is their common ancestor → update LCA
        if (left.second == right.second)
            return {root, left.second + 1};

        // 🔹 Case 2: left subtree deeper → propagate left LCA
        else if (left.second > right.second)
            return {left.first, left.second + 1};

        // 🔹 Case 3: right subtree deeper → propagate right LCA
        else
            return {right.first, right.second + 1};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;  // dfs(root) returns {LCA, depth}
    }
};