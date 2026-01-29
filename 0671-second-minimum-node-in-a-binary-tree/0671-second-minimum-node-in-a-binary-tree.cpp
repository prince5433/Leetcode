class Solution {
public:
    // DFS function to traverse the tree
    // aur saare node values ko vector me store karne ke liye
    void dfs(TreeNode* root, vector<int>& v) {
        // base case: agar node null hai to return
        if(!root) return;

        // current node ki value vector me daal do
        v.push_back(root->val);

        // left subtree traverse karo
        dfs(root->left, v);

        // right subtree traverse karo
        dfs(root->right, v);
    }

    int findSecondMinimumValue(TreeNode* root) {
        // saare node values store karne ke liye vector
        vector<int> v;

        // DFS traversal call
        dfs(root, v);

        // vector ko sort kar diya
        sort(v.begin(), v.end());

        // smallest value (minimum) store kar li
        int x = v[0];

        // vector me traverse karke
        // minimum se badi pehli value dhundh rahe hain
        for(auto it : v) {
            if(it > x) 
                return it;   // wahi second minimum hoga
        }

        // agar koi value minimum se badi mili hi nahi
        // matlab second minimum exist nahi karta
        return -1;
    }
};
