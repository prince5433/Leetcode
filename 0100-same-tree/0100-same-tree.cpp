class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // BASE CASE 1:
        // Agar dono nodes NULL hain, toh dono trees yahan same hain.
        if(p == NULL && q == NULL)
            return true;

        // BASE CASE 2:
        // Agar ek node NULL hai aur doosra NULL nahi hai,
        // toh tree ka structure different hai.
        if(p == NULL || q == NULL)
            return false;

        // CONDITION 1:
        // Dono current nodes ki values compare karo.
        // Agar values different hain, toh trees same nahi ho sakte.
        if(p->val != q->val)
            return false;

        // CONDITION 2:
        // Dono trees ke left subtrees recursively compare karo.
        bool LST = isSameTree(p->left, q->left);

        // Agar left subtree different hai,
        // toh right subtree check karne ki zarurat nahi.
        if(LST == false)
            return false;

        // CONDITION 3:
        // Dono trees ke right subtrees recursively compare karo.
        bool RST = isSameTree(p->right, q->right);

        // Agar right subtree different hai, toh false return karo.
        if(RST == false)
            return false;

        // Agar structure, current values, left aur right
        // dono subtrees same hain, toh trees identical hain.
        return true;
    }
};

// TC: O(N) — Worst case mein dono trees ke corresponding nodes visit honge.
// SC: O(H) — Recursive call stack, H = tree ki height.