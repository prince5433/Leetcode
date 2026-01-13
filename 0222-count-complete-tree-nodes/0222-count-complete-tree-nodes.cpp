/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;                  // node ki value
 *     TreeNode *left;           // left child ka pointer
 *     TreeNode *right;          // right child ka pointer
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Leftmost height nikalta hai (root -> left -> left ...)
    int left(TreeNode* root){
        int lh = 0;
        while(root){
            lh++;
            root = root->left;
        }
        return lh;
    }

    // Rightmost height nikalta hai (root -> right -> right ...)
    int right(TreeNode* root){
        int rh = 0;
        while(root){
            rh++;
            root = root->right;
        }
        return rh;
    }

    int countNodes(TreeNode* root) {
        // Base case: empty tree
        if(!root) return 0;

        // Left aur right height nikal li
        int lh = left(root);
        int rh = right(root);

        // Agar dono height equal hain,
        // to tree perfect binary tree hai
        // nodes = 2^height - 1
        if(lh == rh) 
            return (1 << lh) - 1;

        // Agar perfect nahi hai,
        // to DFS se left aur right subtree count karo
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
