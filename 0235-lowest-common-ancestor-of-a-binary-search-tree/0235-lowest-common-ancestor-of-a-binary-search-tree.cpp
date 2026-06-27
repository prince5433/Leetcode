class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        /*
        Both nodes are greater
        than current node.

        Therefore both must lie
        in the right subtree.
        */
        if (root->val < p->val && root->val < q->val)

            return lowestCommonAncestor(root->right, p, q);

        /*
        Both nodes are smaller
        than current node.

        Therefore both must lie
        in the left subtree.
        */
        else if (root->val > p->val && root->val > q->val)

            return lowestCommonAncestor(root->left, p, q);

        /*
        Otherwise,

        Current node lies between
        p and q (or equals one of them).

        Hence this node is
        the Lowest Common Ancestor.
        */
        else
            return root;
    }
};

/*
---------------- QUICK INTUITION ----------------

BST Property

Left < Root < Right

Using this property,

we can decide
which direction to move.

------------------------------------------------

Case 1

Both nodes are
greater than root.

Example

        6
       / \
      2   8
         / \
        7   9

p = 7
q = 9

Both > 6

Go Right.

------------------------------------------------

Case 2

Both nodes are
smaller than root.

Example

        6
       / \
      2   8
     / \
    0   4

p = 0
q = 4

Both < 6

Go Left.

------------------------------------------------

Case 3

One node lies on left

One node lies on right.

Example

        6
       / \
      2   8

p = 2

q = 8

Current node (6)
splits both paths.

LCA = 6

------------------------------------------------

Case 4

Current node itself
is one of the nodes.

Example

        6
       / \
      2   8

p = 6

q = 8

LCA = 6

Because one node
can be ancestor
of the other.

------------------------------------------------

Dry Run

Tree

          6
         / \
        2   8
       / \
      0   4
         / \
        3   5

Find LCA

p = 3

q = 5

--------------------------------

Current = 6

Both < 6

Go Left

--------------------------------

Current = 2

Both > 2

Go Right

--------------------------------

Current = 4

3 < 4

5 > 4

Split occurs

Answer = 4

------------------------------------------------

Why only one recursive call?

BST property tells us
exactly where both nodes
can exist.

So unlike a normal Binary Tree,

we never search both sides.

------------------------------------------------

TC

Balanced BST

O(log n)

--------------------------------

Worst Case

(Skewed BST)

O(n)

------------------------------------------------

SC

Recursion Stack

Balanced:

O(log n)

Skewed:

O(n)

------------------------------------------------

Pattern

Binary Search Tree

Recursion

Lowest Common Ancestor

Binary Search on Tree
*/