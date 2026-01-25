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
        if (!root) return;                      // base case: if node is NULL, stop

        inorder(root->left, ans);               // traverse left subtree
        ans.push_back(root->val);               // store current node value (BST inorder gives sorted order)
        inorder(root->right, ans);              // traverse right subtree
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);                     // get all values in sorted order using inorder traversal

        map<int, int> mp;
        for (auto it : ans) {
            mp[it]++;                           // count frequency of each value
        }

        int maxi = 0;
        for (auto& it : mp) {
            maxi = max(maxi, it.second);        // find maximum frequency
        }

        vector<int> res;
        for (auto it : mp) {
            if (it.second == maxi) {            // collect all values having maximum frequency
                res.push_back(it.first);
            }
        }

        return res;                             // return all modes
    }
};
