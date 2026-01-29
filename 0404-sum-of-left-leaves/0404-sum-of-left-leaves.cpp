class Solution {
public:
    // ye variable saare left leaves ka sum store karega
    int sum = 0;

    // DFS function jo poore tree ko traverse karega
    void dfs(TreeNode* root) {
        // base case: agar node NULL hai to return
        if(!root) return;

        // check kar rahe hain:
        // 1) root ka left child exist karta ho
        // 2) wo left child ek leaf ho (uske koi children na ho)
        if(root->left && !root->left->left && !root->left->right) {
            // agar left leaf mila, to uski value sum me add kar do
            sum += root->left->val;
        }

        // left subtree traverse
        dfs(root->left);

        // right subtree traverse
        dfs(root->right);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        // pehle poore tree par DFS chalao
        dfs(root);

        // DFS ke baad jo sum bana hai, wahi answer hai
        return sum;
    }
};
