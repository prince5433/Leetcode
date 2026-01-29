class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        // Case 1: agar pehla tree null hai
        // to directly doosra tree return kar do
        if(!root1) return root2;

        // Case 2: agar doosra tree null hai
        // to pehla tree hi answer ka part banega
        if(!root2) return root1;

        // Case 3: dono nodes exist karte hain
        // dono ki value add kar do
        root1->val += root2->val;

        // left subtree ko recursively merge karo
        root1->left = mergeTrees(root1->left, root2->left);

        // right subtree ko recursively merge karo
        root1->right = mergeTrees(root1->right, root2->right);

        // modified root1 ko hi return kar do
        return root1;
    }
};
