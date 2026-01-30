class Solution {
public:
    vector<TreeNode*> ans;          // forest ke roots yahan store honge
    unordered_set<int> st;          // delete karne wale node values ka set

    TreeNode* dfs(TreeNode* root) {
        // base case
        if (!root) return NULL;

        // postorder traversal
        root->left = dfs(root->left);
        root->right = dfs(root->right);

        // agar current node delete karni hai
        if (st.count(root->val)) {

            // left child agar exist karta hai
            // to wo ek new tree ka root ban sakta hai
            if (root->left)
                ans.push_back(root->left);

            // right child agar exist karta hai
            // to wo bhi new root ban sakta hai
            if (root->right)
                ans.push_back(root->right);

            // current node delete ho gaya
            return NULL;
        }

        // delete nahi hua to node as it is return
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        // delete list ko set me daalo
        for (int x : to_delete)
            st.insert(x);

        // DFS chalao
        root = dfs(root);

        // agar original root delete nahi hua
        // to wo bhi forest ka part hai
        if (root)
            ans.push_back(root);

        return ans;
    }
};
