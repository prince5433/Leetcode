class Solution {
public:
    int maxDia = 0;  // \U0001f539 Global variable to store the maximum diameter

    // \U0001f539 DFS function that returns the height of the current subtree
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;  // base case

        // recursively find left and right subtree heights
        int left = dfs(root->left);
        int right = dfs(root->right);

        // update maximum diameter if this node gives a longer path
        maxDia = max(maxDia, left + right);

        // return height of this node
        return 1 + max(left, right);
    }

    // \U0001f539 Main function to compute the diameter
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);        // start DFS traversal
        return maxDia;    // final answer
    }
};
