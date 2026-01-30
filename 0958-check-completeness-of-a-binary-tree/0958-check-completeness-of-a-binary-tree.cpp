class Solution {
public:
//dfs
    // Count total number of nodes in the tree
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // DFS to check completeness using index positions
    bool dfs(TreeNode* root, int index, int n) {

        // NULL node is valid
        if(!root) return true;

        // If index exceeds total nodes → gap found
        if(index >= n) return false;

        // Check left and right subtrees
        return dfs(root->left, 2 * index + 1, n) &&
               dfs(root->right, 2 * index + 2, n);
    }

    // Main function to check if tree is complete
    bool isCompleteTree(TreeNode* root) {

        // Total nodes count
        int n = countNodes(root);

        // Start DFS with root index = 0
        return dfs(root, 0, n);
    }
};
