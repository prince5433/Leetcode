/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    // x aur y ki depth store karne ke liye
    int dx = -1, dy = -1;

    // x aur y ke parent store karne ke liye
    TreeNode* px = nullptr;
    TreeNode* py = nullptr;

    // DFS function jo depth aur parent track karta hai
    void dfs(TreeNode* root, TreeNode* parent, int depth, int x, int y) {
        // base case: agar node null hai
        if(!root) return;

        // agar current node x hai
        if(root->val == x) {
            dx = depth;      // x ki depth save karo
            px = parent;     // x ka parent save karo
        }

        // agar current node y hai
        if(root->val == y) {
            dy = depth;      // y ki depth save karo
            py = parent;     // y ka parent save karo
        }

        // left subtree me DFS call
        dfs(root->left, root, depth + 1, x, y);

        // right subtree me DFS call
        dfs(root->right, root, depth + 1, x, y);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        // DFS start karo root se
        dfs(root, nullptr, 0, x, y);

        // cousins tab honge jab:
        // 1) x aur y ki depth same ho
        // 2) x aur y ke parent different ho
        return (dx == dy) && (px != py);
    }
};
