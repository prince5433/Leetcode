class Solution {
public:
    // \U0001f539 Recursive helper function to explore all paths
    void helper(TreeNode* root, vector<int> v, vector<vector<int>>& ans, int sum) {
        if(root == NULL) return;  // base case: reached null node

        // \U0001f538 Leaf node condition
        if(root->left == NULL && root->right == NULL) {
            // If the remaining sum equals current node value → valid path
            if(root->val == sum) {
                v.push_back(root->val);   // include this leaf
                ans.push_back(v);         // add full path to answer
            }
            return; // stop recursion for leaf
        }

        // \U0001f538 Add current node to path
        v.push_back(root->val);

        // \U0001f538 Recur for left and right subtrees
        // Reduce sum by current node’s value since it’s included in path
        helper(root->left, v, ans, sum - root->val);
        helper(root->right, v, ans, sum - root->val);
    }

    // \U0001f539 Main function
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;  // to store all valid paths
        vector<int> v;            // to store one current path
        helper(root, v, ans, targetSum);
        return ans;
    }
};
