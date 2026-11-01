class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        // WHY?
        // Agar tree empty hai, toh kisi bhi level par node nahi hai.
        // Isliye directly empty answer return kar do.
        if(root == NULL)
            return ans;

        queue<TreeNode*> q;

        // Root ko queue mein daal diya.
        // BFS hamesha root se start hota hai.
        q.push(root);

        // Jab tak queue mein nodes hain, tab tak traversal chalega.
        while(!q.empty()) {

            // WHY?
            // Current level par jitne nodes hain, unki count store karo.
            // Isse hum current level ko next level se separate rakh paayenge.
            int n = q.size();

            vector<int> level;

            // Current level ke exactly n nodes process honge.
            while(n--) {

                // Queue ka front node nikalo aur process karo.
                TreeNode* curr = q.front();
                q.pop();

                // Current node ki value current level ke answer mein add karo.
                level.push_back(curr->val);

                // WHY?
                // Left child ko queue mein add karo.
                // Ye next level mein process hoga.
                if(curr->left)
                    q.push(curr->left);

                // WHY?
                // Right child ko queue mein add karo.
                // Ye bhi next level mein process hoga.
                if(curr->right)
                    q.push(curr->right);
            }

            // Current level complete ho gaya.
            // Ab uski values final answer mein add kar do.
            ans.push_back(level);
        }

        return ans;
    }
};

// TC: O(N) — Har node exactly ek baar process hota hai.
// SC: O(N) — Queue mein maximum O(N) nodes ho sakte hain.