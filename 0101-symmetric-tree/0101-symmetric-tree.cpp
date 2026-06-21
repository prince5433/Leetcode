class Solution {
public:
    // Checks whether two trees are mirror images
    bool isMirror(TreeNode* p, TreeNode* q) {

        /*
        Mirror means:

        p->left  ↔ q->right
        p->right ↔ q->left
        */

        // Both nodes absent
        if (p == NULL && q == NULL)
            return true;

        // One node present, other absent
        if (p == NULL && q != NULL)
            return false;

        if (q == NULL && p != NULL)
            return false;

        // Values must match
        if (p->val != q->val)
            return false;

        /*
        Mirror Check:

        Left of first tree
        should match
        Right of second tree
        */
        bool LST = isMirror(p->left, q->right);

        if (LST == false)
            return false;

        /*
        Right of first tree
        should match
        Left of second tree
        */
        bool RST = isMirror(p->right, q->left);

        if (RST == false)
            return false;

        return true;
    }

    bool isSymmetric(TreeNode* root) {

        // Empty tree is symmetric
        if (root == NULL)
            return true;

        /*
        Tree is symmetric iff

        left subtree
        and
        right subtree

        are mirrors of each other.
        */
        return isMirror(root->left, root->right);
    }
};

/*
---------------- QUICK INTUITION ----------------

Symmetric Tree means:

Left half should be
mirror image of right half.

------------------------------------------------

Example:

          1
        /   \
       2     2
      / \   / \
     3   4 4   3

Mirror Perfectly ✅

Answer = true

------------------------------------------------

Example:

          1
        /   \
       2     2
        \     \
         3     3

Not Mirror ❌

Answer = false

------------------------------------------------

Mirror Rule

For two nodes p and q:

1. Values same hone chahiye

2. p->left
   should match
   q->right

3. p->right
   should match
   q->left

------------------------------------------------

Dry Run

          1
        /   \
       2     2

Call:

isMirror(2,2)

Values same ✅

Check:

isMirror(NULL,NULL)

true

Check:

isMirror(NULL,NULL)

true

Return true

------------------------------------------------

Recursive Formula

isMirror(p,q)

=

(p->val == q->val)

AND

isMirror(
    p->left,
    q->right
)

AND

isMirror(
    p->right,
    q->left
)

------------------------------------------------

TC

Every node visited once.

O(n)

------------------------------------------------

SC

Recursion Stack:

O(h)

Balanced Tree:
O(log n)

Skewed Tree:
O(n)

------------------------------------------------

Pattern

Binary Tree
DFS
Recursion
Mirror Tree
Symmetric Tree Check
*/