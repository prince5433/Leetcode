class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        /*
        Intuition:

        Har node par:

        left subtree ↔ right subtree

        swap kar do.

        Fir recursively dono
        subtrees ko bhi invert karo.
        */

        // Empty tree
        if (root == NULL)
            return NULL;

        // Swap left and right child
        TreeNode* temp = root->left;

        root->left = root->right;

        root->right = temp;

        // Invert left subtree
        invertTree(root->left);

        // Invert right subtree
        invertTree(root->right);

        return root;
    }
};

/*
---------------- QUICK INTUITION ----------------

Original Tree:

        4
      /   \
     2     7
    / \   / \
   1  3  6  9

--------------------------------

After swapping at root:

        4
      /   \
     7     2
    / \   / \
   6  9  1  3

--------------------------------

Recursive Idea

For every node:

swap(left,right)

Then do same for:

left subtree
right subtree

------------------------------------------------

Dry Run

Node = 4

Swap:

2 ↔ 7

        4
      /   \
     7     2

Now recurse on:

7 subtree
2 subtree

Eventually every node
gets mirrored.

------------------------------------------------

Visualization

Before:

        Root
       /    \
    Left   Right

After:

        Root
       /    \
    Right   Left

------------------------------------------------

TC

Every node visited once.

O(n)

------------------------------------------------

SC

Recursion Stack:

O(h)

h = height of tree

Balanced Tree:
O(log n)

Skewed Tree:
O(n)

------------------------------------------------

Pattern

Binary Tree
DFS
Recursion
Tree Transformation
Mirror Tree

------------------------------------------------

Interview One-Liner

"At each node I swap its left and right child, then recursively invert both
subtrees. Since every node is processed exactly once, the complexity is O(n)."
*/