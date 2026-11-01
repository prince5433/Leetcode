class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        // BASE CASE:
        // Agar tree empty hai, toh right side se bhi koi node visible nahi hogi.
        if(root == NULL)
            return ans;

        queue<TreeNode*> qu;

        // BFS traversal root node se start hoga.
        qu.push(root);

        // Jab tak queue mein nodes hain, tab tak har level process karo.
        while(!qu.empty()) {

            // Current level par kitne nodes hain, unki count store karo.
            // Ye ensure karega ki hum ek time par sirf current level process karein.
            int sz = qu.size();

            // Current level ke saare nodes process karo.
            for(int i = 1; i <= sz; i++) {

                // Queue ke front se node nikalo.
                TreeNode* temp = qu.front();
                qu.pop();

                // WHY i == sz?
                // Current level ka last node rightmost node hota hai.
                // Right side se humein isi node ka view dikhega.
                if(i == sz)
                    ans.push_back(temp->val);

                // Left child ko queue mein add karo,
                // taaki next level mein process ho sake.
                if(temp->left)
                    qu.push(temp->left);

                // Right child ko queue mein add karo,
                // taaki next level mein process ho sake.
                if(temp->right)
                    qu.push(temp->right);
            }
        }

        return ans;
    }
};

// TC: O(N) — Har node exactly ek baar process hota hai.
// SC: O(N) — Queue mein worst case O(N) nodes ho sakte hain.