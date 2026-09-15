class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        // WHY?
        // Empty tree hai to answer bhi empty hoga.
        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int n = q.size(); // Current level ke nodes

            vector<int> level;

            while(n--) {

                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                // WHY?
                // Children ko queue mein daal rahe hain
                // taaki next level mein process ho.
                if(curr->left)
                    q.push(curr->left);

                if(curr->right)
                    q.push(curr->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};