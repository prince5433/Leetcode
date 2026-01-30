class Solution {
public:
    // Function to return the right side view of a binary tree using BFS
    vector<int> rightSideView(TreeNode* root) {

        // Agar tree empty hai → right view bhi empty
        if(!root) return {};

        vector<int> ans;                 // right side view store karega
        queue<TreeNode*> qu;              // level order traversal ke liye queue

        // root ko queue me daal do
        qu.push(root);

        // Jab tak queue empty nahi hoti
        while(!qu.empty()) {

            int n = qu.size();            // current level ke nodes count
            TreeNode* node = NULL;        // last node of current level ko store karega

            // current level ke saare nodes process karo
            while(n--) {
                node = qu.front();        // queue ka front node
                qu.pop();

                // left child ko pehle push karo
                if(node->left) 
                    qu.push(node->left);

                // right child ko baad me push karo
                if(node->right) 
                    qu.push(node->right);
            }

            // level ka last processed node → right side se visible
            ans.push_back(node->val);
        }

        // final right side view return karo
        return ans;
    }
};
