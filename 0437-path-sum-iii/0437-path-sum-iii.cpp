class Solution {
public:
    // \U0001f539 Helper function: counts paths starting **from the current node** that sum to 'sum'
    void helper(TreeNode* root, long long sum, int& count) {
        if(root == NULL) return; // base case

        // if current node itself completes the required sum
        if((long long)root->val == sum) 
            count++;

        // continue to explore left and right subtrees,
        // decreasing 'sum' by the current node's value
        helper(root->left, sum - (long long)(root->val), count);
        helper(root->right, sum - (long long)(root->val), count);
    }

    // \U0001f539 Main function
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0; // base case

        int count = 0;

        // count all paths that start from this current root
        helper(root, (long long)targetSum, count);

        // recursively count paths starting from left and right subtrees
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);

        return count;
    }
};
