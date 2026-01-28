class Solution {
public:
    // DFS function jo root se leaf tak binary number build karta hai
    int dfs(TreeNode* root, int curr) {

        // base case: agar node null hai to 0 return karo
        if(!root) return 0;

        // current binary number update karo
        // curr * 2  -> left shift
        // + root->val -> current bit (0 ya 1) add
        curr = curr * 2 + root->val;

        // agar leaf node hai (root-to-leaf path complete)
        if(!root->left && !root->right)
            return curr;   // is path ka decimal value return

        // left aur right subtree se aane wale sums ko add karo
        return dfs(root->left, curr) + dfs(root->right, curr);
    }

    int sumRootToLeaf(TreeNode* root) {
        // DFS start karo initial value 0 ke saath
        return dfs(root, 0);
    }
};
