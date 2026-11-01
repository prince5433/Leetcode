class Solution {
public:
    int maxDepth(TreeNode* root) {

        // BASE CASE:
        // Agar current node NULL hai, iska matlab
        // yahan tree exist nahi karta, toh depth 0 hogi.
        if(root == NULL)
            return 0;

        // RECURSIVE CALL 1:
        // Current node ke left subtree ki maximum depth find karo.
        int leftdepth = maxDepth(root->left);

        // RECURSIVE CALL 2:
        // Current node ke right subtree ki maximum depth find karo.
        int rightdepth = maxDepth(root->right);

        // WHY 1 + max()?
        // 1 current node ki apni depth represent karta hai.
        // max() left aur right subtree mein se deeper subtree choose karta hai.
        // Dono ko add nahi karna, kyunki ek root-to-leaf path mein
        // hum ya toh left jayenge ya right.
        return 1 + max(leftdepth, rightdepth);
    }
};

// TC: O(N) — Har node exactly ek baar visit hota hai.
// SC: O(H) — Recursive call stack, H = tree ki height.
// Worst case: O(N), balanced tree: O(log N).