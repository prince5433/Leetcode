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

    // DFS function jo root-to-leaf number build karta hai
    int dfs(TreeNode* root, int curr) {

        // base case: agar node null hai to sum me 0 contribute karega
        if(!root) return 0;

        // current number update karo
        // decimal number ban raha hai: previous * 10 + current digit
        curr = curr * 10 + root->val;

        // agar leaf node mil gayi (path complete)
        if(!root->left && !root->right) {
            // is path ka number return kar do
            return curr;
        }

        // left aur right subtree se aane wale numbers ka sum
        return dfs(root->left, curr) + dfs(root->right, curr);
    }

    int sumNumbers(TreeNode* root) {
        // DFS start karo initial value 0 ke saath
        return dfs(root, 0);
    }
};
