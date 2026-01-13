/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;                  // value stored in node
 *     TreeNode *left;           // pointer to left child
 *     TreeNode *right;          // pointer to right child
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int countNodes(TreeNode* root) {
        // Base case:
        // agar tree ya subtree empty hai, to nodes = 0
        if (!root) return 0;

        // Recursive case:
        // 1 -> current node
        // countNodes(root->left) -> left subtree ke nodes
        // countNodes(root->right) -> right subtree ke nodes
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
