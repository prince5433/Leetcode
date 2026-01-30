class Solution {
public:
    // Ye function check karta hai ki do trees bilkul same hain ya nahi
    bool isSame(TreeNode* s, TreeNode* r) {
        // Dono NULL hain → same tree
        if(!s && !r) return true;

        // Ek NULL aur ek non-NULL → structure different
        if(!s || !r) return false;

        // Value match nahi hui → same tree nahi
        if(s->val != r->val) return false;

        // Left aur right subtree dono same hone chahiye
        return isSame(s->left, r->left) && isSame(s->right, r->right);
    }

    // Ye function check karta hai ki subRoot, root ka subtree hai ya nahi
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Agar root NULL ho gaya → subtree possible nahi
        if(!root) return false;

        // Agar current node se poora tree match ho jaye
        if(isSame(root, subRoot)) return true;

        // Nahi to left ya right subtree me search karo
        return isSubtree(root->left, subRoot) || 
               isSubtree(root->right, subRoot);
    }
};
