class Solution {
public:
    unordered_map<string, int> mp;   // subtree serialization -> frequency
    vector<TreeNode*> ans;

    string dfs(TreeNode* root) {
        // NULL node ko represent karo
        if (!root) return "#";

        // postorder: left, right, node
        string left = dfs(root->left);
        string right = dfs(root->right);

        // current subtree ka serialization
        string s = to_string(root->val) + "," + left + "," + right;

        // frequency increase
        mp[s]++;

        // agar subtree 2nd time mila, to answer me add
        if (mp[s] == 2)
            ans.push_back(root);

        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
