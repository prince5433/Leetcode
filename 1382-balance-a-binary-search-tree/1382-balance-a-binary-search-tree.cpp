class Solution {
public:
    // Step 1: Store inorder traversal (gives sorted values of BST)
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    // Step 2: Build a balanced BST from sorted array
    TreeNode* helper(vector<int>& nums, int lo, int hi) {
        if (lo > hi) return NULL;

        int mid = lo + (hi - lo) / 2;           // middle element becomes root
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = helper(nums, lo, mid - 1); // build left subtree
        root->right = helper(nums, mid + 1, hi);// build right subtree

        return root;
    }

    // Step 3: Convert unbalanced BST → balanced BST
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);         // get sorted nodes
        return helper(ans, 0, ans.size() - 1);
    }
};
