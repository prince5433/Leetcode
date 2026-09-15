class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // \U0001f539 Base case 1: if both nodes are NULL → both trees are empty here → same
        if (p == NULL && q == NULL) 
            return true;

        // \U0001f539 Base case 2: if one is NULL but the other is not → structure mismatch
        if (p == NULL && q != NULL) 
            return false;
        if (q == NULL && p != NULL) 
            return false; 

        // \U0001f539 Condition 1: if current node values are not equal → trees differ
        if (p->val != q->val) 
            return false;

        // \U0001f539 Condition 2: check if left subtrees are same
        bool LST = isSameTree(p->left, q->left);
        if (LST == false) 
            return false;   // left side mismatch → stop further checks

        // \U0001f539 Condition 3: check if right subtrees are same
        bool RST = isSameTree(p->right, q->right);
        if (RST == false) 
            return false;   // right side mismatch → stop further checks

        // \U0001f539 If all checks passed → trees are identical
        return true;
    }
};
