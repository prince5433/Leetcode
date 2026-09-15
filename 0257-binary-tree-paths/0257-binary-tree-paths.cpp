class Solution {
public:
    // \U0001f539 Helper function to generate all root-to-leaf paths
    void helper(TreeNode* root, string s, vector<string>& ans) {
        // Base case: if current node is NULL, return (no path to explore)
        if (root == NULL) return;

        // Convert current node value to string
        string a = to_string(root->val);

        // \U0001f538 If it's a leaf node (no left or right child)
        if (root->left == NULL && root->right == NULL) {
            // Add the leaf node value to the current path string
            s += a;
            // Store this complete path in the answer vector
            ans.push_back(s);
            return; // backtrack
        }

        // \U0001f539 Recurse for left and right subtrees
        // Append current node value and "->" for the next node
        helper(root->left,  s + a + "->", ans);
        helper(root->right, s + a + "->", ans);
    }

    // \U0001f539 Main function that initializes the process
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;        // to store all root-to-leaf paths
        helper(root, "", ans);     // start DFS traversal
        return ans;                // return all collected paths
    }
};
