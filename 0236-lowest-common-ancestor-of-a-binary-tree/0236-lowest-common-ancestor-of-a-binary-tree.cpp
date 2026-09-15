/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //mik solutino
        // 🔹 Base Case 1:
        // Agar current node NULL hai → kuch nahi mila
        if(root == NULL) return NULL;

        // 🔹 Base Case 2:
        // Agar current node hi p ya q hai → wahi answer ho sakta hai
        // (kyunki LCA wo node bhi ho sakta hai jo khud p ya q ho)
        if(root == p || root == q) return root;

        // 🔹 Recursively left subtree me search karo
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // 🔹 Recursively right subtree me search karo
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // 🔹 Case 1:
        // Agar p aur q dono alag-alag side me mile
        // → current node hi unka Lowest Common Ancestor hai
        if(left != NULL && right != NULL) return root;

        // 🔹 Case 2:
        // Agar sirf left side me mila → answer left subtree me hai
        if(left != NULL) return left;

        // 🔹 Case 3:
        // Agar sirf right side me mila → answer right subtree me hai
        return right;
    }
};