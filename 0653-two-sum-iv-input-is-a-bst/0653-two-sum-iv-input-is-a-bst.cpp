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
    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;                  // base case: if node is NULL, stop

        inorder(root->left, ans);           // traverse left subtree
        ans.push_back(root->val);           // store current node value (BST inorder gives sorted array)
        inorder(root->right, ans);          // traverse right subtree
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, ans);                 // get sorted values from BST

        unordered_map<int, int> mp;         // store values we have seen so far (for 2-sum check)

        for (int i = 0; i < ans.size(); i++) {
            int need = k - ans[i];          // required value to make sum = k

            if (mp.count(need)) {           // if required value already exists, pair found
                return true;
            }

            mp[ans[i]]++;                   // mark current value as seen
        }

        return false;                       // no pair found
    }
};
