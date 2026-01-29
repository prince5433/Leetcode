class Solution {
public:
    // DFS function jo tree traverse karta hai
    // aur sirf leaf nodes ki values vector me store karta hai
    void dfs(TreeNode* root, vector<int>& v) {
        // base case: agar node null ho
        if(!root) return;

        // agar current node leaf node hai
        // (na left child, na right child)
        if(!root->left && !root->right) {
            // leaf ki value vector me push kar do
            v.push_back(root->val);
            return;
        }

        // left subtree traverse karo
        dfs(root->left, v);

        // right subtree traverse karo
        dfs(root->right, v);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // dono trees ke leaf sequences store karne ke liye vectors
        vector<int> v1, v2;

        // first tree ke leaf nodes collect
        dfs(root1, v1);

        // second tree ke leaf nodes collect
        dfs(root2, v2);

        // agar dono leaf sequences same hain
        // to trees leaf-similar hain
        return v1 == v2;
    }
};
