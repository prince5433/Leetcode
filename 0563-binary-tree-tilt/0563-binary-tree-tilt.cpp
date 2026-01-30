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
    int ans = 0;   // poore tree ka total tilt store karega

    int dfs(TreeNode* root) {
        // agar node NULL hai to subtree sum = 0
        if (!root) return 0;

        // agar leaf node hai (left & right dono NULL)
        // to iska subtree sum sirf uski value hogi
        // aur tilt = |0 - 0| = 0 (isliye ans me kuch add nahi)
        if (!root->left && !root->right)
            return root->val;

        // left subtree ka sum nikaalo
        int l = dfs(root->left);

        // right subtree ka sum nikaalo
        int r = dfs(root->right);

        // current node ka tilt = |leftSum - rightSum|
        // ise global answer me add kar do
        ans += abs(l - r);

        // current subtree ka total sum return
        return l + r + root->val;
    }

    int findTilt(TreeNode* root) {
        // DFS (postorder traversal) call
        dfs(root);

        // final accumulated tilt return
        return ans;
    }
};
