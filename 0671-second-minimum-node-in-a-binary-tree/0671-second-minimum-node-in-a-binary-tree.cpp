class Solution {
public:
//better sc
    // ans second minimum value ko store karega
    // initially bahut badi value rakhi hai
    long ans = LONG_MAX;

    // DFS function jo tree traverse karta hai
    void dfs(TreeNode* root, int firstMin) {
        // base case: agar node null hai
        if(!root) return;

        // agar current node ki value
        // first minimum se badi hai
        // aur ab tak ke answer se chhoti hai
        // to answer update kar do
        if(root->val > firstMin && root->val < ans)
            ans = root->val;

        // left subtree traverse karo
        dfs(root->left, firstMin);

        // right subtree traverse karo
        dfs(root->right, firstMin);
    }

    int findSecondMinimumValue(TreeNode* root) {
        // root ka value hi minimum hota hai (problem ki property)
        // DFS call kar rahe hain
        dfs(root, root->val);

        // agar ans update hua hai to wahi second minimum
        // warna second minimum exist nahi karta
        return ans == LONG_MAX ? -1 : ans;
    }
};
