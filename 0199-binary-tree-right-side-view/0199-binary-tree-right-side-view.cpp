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
    vector<int> rightSideView(TreeNode* root) {
         vector<int> ans;
         if(root==NULL) return ans;
         queue<TreeNode*> qu;
         qu.push(root);
         while(!qu.empty()){
            int sz=qu.size();
            for(int i=1;i<=sz;i++){
                TreeNode* temp=qu.front();
                qu.pop();
                if(i==sz) ans.push_back(temp->val);
                if(temp->left) qu.push(temp->left);
                if(temp->right) qu.push(temp->right);
            }
           
         }
         return ans;
    }
};