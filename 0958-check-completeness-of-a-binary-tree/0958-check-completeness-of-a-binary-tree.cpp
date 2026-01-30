class Solution {
public:
//bfs
    // Function to check if a binary tree is complete using BFS
    bool isCompleteTree(TreeNode* root) {

        // Queue for level order traversal
        queue<TreeNode*> q;
        q.push(root);

        // Flag to mark if NULL node has been seen
        bool seenNull = false;

        // Traverse level by level
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // If NULL node is found
            if(node == NULL) {
                // After this, no non-NULL node should appear
                seenNull = true;
            }
            else {
                // If we already saw NULL and now found a node → not complete
                if(seenNull) return false;

                // Push left and right children (even if they are NULL)
                q.push(node->left);
                q.push(node->right);
            }
        }

        // Tree satisfies complete binary tree property
        return true;
    }
};
