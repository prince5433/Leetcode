class Solution {
public:
    // 🔹 Function to calculate the height (levels) of a binary tree
    int levels(TreeNode* root) {
        if (root == NULL) 
            return 0; // agar node NULL hai → height 0
        // height = 1 + max height of left or right subtree
        return 1 + max(levels(root->left), levels(root->right));
    }

    // 🔹 Function to check if a binary tree is height-balanced
    bool isBalanced(TreeNode* root) {
        if (root == NULL) 
            return true; // empty tree is always balanced ✅

        // 🔸 Step 1: calculate height of left and right subtrees
        int lst = levels(root->left);
        int rst = levels(root->right);

        // 🔸 Step 2: find absolute difference between heights
        int diff = abs(lst - rst);

        // 🔸 Step 3: recursively check if left and right subtrees are balanced
        bool leftBalanced = isBalanced(root->left);
        bool rightBalanced = isBalanced(root->right);

        // 🔸 Step 4: current node is balanced if:
        //  height difference ≤ 1  &&  both subtrees are balanced
        return (diff <= 1) && leftBalanced && rightBalanced;
    }
};
