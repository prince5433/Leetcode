class Solution {
public:

    // WHY levels()?
    // Ye function tree ki total height / number of levels nikalta hai.
    // Current levelOrder() mein iska use nahi ho raha,
    // isliye technically is function ki zarurat nahi hai.
    int levels(TreeNode* root) {

        // WHY 0?
        // NULL node ke neeche koi level nahi hota.
        if(root == NULL)
            return 0;

        // WHY 1 + max(left, right)?
        // Current root khud 1 level contribute karta hai.
        // Uske baad left aur right subtree mein se
        // jo zyada deep hai, uski height lenge.
        return 1 + max(levels(root->left),
                       levels(root->right));
    }


    // WHY separate helper function?
    // Actual BFS/Queue ka pura logic yahan rakha hai,
    // taaki main levelOrder() simple rahe.
    void levelOrderQueue(TreeNode* root, vector<vector<int>>& ans) {

        // WHY?
        // Agar tree empty hai, to traversal karne ke liye kuch nahi hai.
        if(root == NULL)
            return;


        // WHY queue?
        // Level Order Traversal mein humein
        // pehle parent nodes process karne hain,
        // phir unke children.
        //
        // Queue FIFO follow karti hai:
        // First In -> First Out
        queue<TreeNode*> q;

        // WHY root ko queue mein daala?
        // Traversal root se start hoga.
        q.push(root);


        // Jab tak queue mein nodes hain,
        // tab tak tree ke levels process karte rahenge.
        while(q.size() > 0) {

            // WHY levelsize?
            // Current level par exactly kitne nodes hain,
            // ye store karna zaroori hai.
            //
            // Example:
            //       1
            //      / \
            //     2   3
            //
            // Initially q = [1]
            // levelsize = 1
            //
            // Next q = [2,3]
            // levelsize = 2
            //
            // Isse hume pata chalega ki current level
            // ke nodes kahan tak process karne hain.
            int levelsize = q.size();


            // Current level ke values yahan store hongi.
            vector<int> level;


            // WHY exactly levelsize times?
            // Sirf current level ke nodes process karne hain.
            //
            // Agar levelsize = 2 hai,
            // to sirf 2 nodes process honge.
            // Unke children queue mein add honge,
            // lekin next iteration mein process honge.
            for(int i = 1; i <= levelsize; i++) {

                // Queue ke front se current node nikalo.
                TreeNode* temp = q.front();
                q.pop();


                // Current node ki value ko current level mein add karo.
                level.push_back(temp->val);


                // WHY left child ko queue mein push?
                // Left child next level ka part hoga.
                if(temp->left != NULL)
                    q.push(temp->left);


                // WHY right child ko queue mein push?
                // Right child bhi next level ka part hoga.
                if(temp->right != NULL)
                    q.push(temp->right);
            }


            // Current level complete ho gaya.
            // Ab us level ki values answer mein add kar do.
            ans.push_back(level);
        }
    }


    vector<vector<int>> levelOrder(TreeNode* root) {

        // Final answer:
        // Har inner vector = ek complete level.
        vector<vector<int>> ans;

        // BFS helper function call karo.
        levelOrderQueue(root, ans);


        // Complete level-order traversal return karo.
        return ans;
    }
};