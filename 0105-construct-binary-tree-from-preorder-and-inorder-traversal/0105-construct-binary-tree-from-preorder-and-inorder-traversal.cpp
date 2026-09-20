class Solution {
public:
    // \U0001f539 Helper function to recursively build the tree
    TreeNode* build(vector<int>& pre, int prelo, int prehi,
                    vector<int>& in, int inlo, int inhi) {

        // Base case: invalid range → no node to create
        if(prelo > prehi) return NULL;

        // The first element of preorder segment is always the root
        TreeNode* root = new TreeNode(pre[prelo]);

        // Base case: only one element (leaf node)
        if(prelo == prehi) return root;

        // Find root position in inorder traversal
        int i = inlo;
        while(i <= inhi) {
            if(in[i] == pre[prelo]) break;  // found root in inorder
            i++;
        }

        // Number of elements in left subtree
        int lc = i - inlo;      // left count
        // Number of elements in right subtree
        int rc = inhi - i;      // right count (not directly used)

        // Build left subtree using:
        // preorder: [prelo+1 ... prelo+lc]
        // inorder : [inlo ... i-1]
        root->left = build(pre, prelo + 1, prelo + lc, in, inlo, i - 1);

        // Build right subtree using:
        // preorder: [prelo+lc+1 ... prehi]
        // inorder : [i+1 ... inhi]
        root->right = build(pre, prelo + lc + 1, prehi, in, i + 1, inhi);

        return root; // return the constructed subtree root
    }

    // \U0001f539 Main function
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        return build(pre, 0, n - 1, in, 0, n - 1);
    }
};
