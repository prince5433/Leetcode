class Solution {
public:
    bool isUnivalTree(TreeNode* root) {

        // base case: agar node null hai to unival hi mana jayega
        if(root == nullptr) return true;

        // agar left child exist karta hai aur uski value root se different hai
        if(root->left && root->left->val != root->val)
            return false;

        // agar right child exist karta hai aur uski value root se different hai
        if(root->right && root->right->val != root->val)
            return false;

        // recursively left aur right subtree check karo
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};
