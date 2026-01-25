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
 void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;                 // base case: null node

        inorder(root->left, ans);          // visit left subtree
        ans.push_back(root->val);          // store current node value (in sorted order for BST)
        inorder(root->right, ans);         // visit right subtree
    }

    int getMinimumDifference(TreeNode* root) {
        
  vector<int> ans;
        inorder(root, ans);                // get inorder traversal (sorted values)

        int mind = INT_MAX;                // minimum difference tracker

        for (int i = 1; i < ans.size(); i++) {
            int diff = ans[i] - ans[i - 1]; // diff of adjacent sorted values
            mind = min(mind, diff);         // update minimum
        }

        return mind;                        // final minimum difference
    }
};