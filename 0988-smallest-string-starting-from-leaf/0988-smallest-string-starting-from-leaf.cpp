class Solution {
public:
    // saari leaf->root strings store karne ke liye
    vector<string> v;

    // DFS function jo root->leaf order me string build karta hai
    void dfs(TreeNode* root, string s) {
        // base case: agar node null hai
        if(!root) return;

        // current node ka character string ke end me add karo
        // (abhi string root -> leaf order me ban rahi hai)
        s.push_back('a' + root->val);

        // agar leaf node mil gayi
        if(!root->left && !root->right) {
            // hume leaf -> root order chahiye,
            // isliye yahan string reverse kar rahe hain
            reverse(s.begin(), s.end());

            // reversed string vector me store karo
            v.push_back(s);
            return;
        }

        // left subtree ke liye DFS
        dfs(root->left, s);

        // right subtree ke liye DFS
        dfs(root->right, s);
    }

    string smallestFromLeaf(TreeNode* root) {
        // DFS start karo empty string se
        dfs(root, "");

        // saari strings ko lexicographically sort karo
        sort(v.begin(), v.end());

        // sabse chhoti string return karo
        return v[0];
    }
};
