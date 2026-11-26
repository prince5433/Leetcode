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
    int solve(TreeNode* root, int& moves) {
        // NULL node ke paas na coins hain, na hi coins ki requirement.
        if (root == NULL) return 0;

        // Left aur right subtree ko balance karo.
        // l/r batayenge ki subtree ke paas kitne extra coins hain
        // (positive = extra, negative = coins ki kami).
        int l = solve(root->left, moves);
        int r = solve(root->right, moves);

        // Left subtree se root tak |l| coins move karne padenge.
        // Right subtree se root tak |r| coins move karne padenge.
        // Har edge par ek coin move karna ek move count hota hai.
        moves += abs(l) + abs(r);

        // Current subtree ke total coins = left balance + right balance + root ke coins.
        // Is subtree ke har node ko 1 coin chahiye, isliye node ka 1 coin
        // yahin rakhkar baaki extra/shortage parent ko return karte hain.
        // Positive result = parent ko extra coins de sakte hain.
        // Negative result = parent se utne coins lene honge.
        return (l + r + root->val) - 1;
    }

    int distributeCoins(TreeNode* root) {
        int moves = 0;

        // Root se DFS start karo; har subtree apna balance parent ko return karega.
        solve(root, moves);

        // Saare edges par required coin movements ka total.
        return moves;
    }
};