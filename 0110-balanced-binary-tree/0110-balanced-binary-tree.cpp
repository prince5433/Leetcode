class Solution {
public:
    // Returns height of tree
    int levels(TreeNode* root) {

        // Empty tree height = 0
        if (root == NULL)
            return 0;

        /*
        Height =
        1 + maximum height
        of left and right subtree
        */
        return 1 + max(levels(root->left), levels(root->right));
    }

    bool isBalanced(TreeNode* root) {

        /*
        Balanced Tree:

        For every node,

        |left height - right height| <= 1
        */

        // Empty tree is balanced
        if (root == NULL)
            return true;

        // Height of left subtree
        int lst = levels(root->left);

        // Height of right subtree
        int rst = levels(root->right);

        // Height difference
        int diff = abs(lst - rst);

        // Check left subtree
        bool leftbalanced = isBalanced(root->left);

        // Check right subtree
        bool rightbalanced = isBalanced(root->right);

        return (diff <= 1) && leftbalanced && rightbalanced;
    }
};

/*
---------------- QUICK INTUITION ----------------

A tree is balanced if:

For EVERY node,

|height(left) - height(right)| <= 1

------------------------------------------------

Example:

        3
       / \
      9   20
         /  \
        15   7

Left Height = 1
Right Height = 2

Difference = 1

Balanced ✅

------------------------------------------------

Example:

        1
       /
      2
     /
    3

At root:

Left Height = 2
Right Height = 0

Difference = 2

Not Balanced ❌

------------------------------------------------

How Code Works?

For every node:

1. Find left height
2. Find right height
3. Check difference <= 1
4. Recursively verify left subtree
5. Recursively verify right subtree

All conditions true ⇒ Balanced

------------------------------------------------

Dry Run

Tree:

      1
     / \
    2   3

Node 2:

diff = 0

Balanced

--------------------------------

Node 3:

diff = 0

Balanced

--------------------------------

Node 1:

left height = 1

right height = 1

diff = 0

Balanced

Answer = true

------------------------------------------------

IMPORTANT

This solution is correct
but NOT optimal.

Why?

For every node,
levels() recalculates heights again.

Same heights are computed
many times.

------------------------------------------------

TC

levels() = O(n)

Called for every node.

Worst Case:

O(n²)

------------------------------------------------

SC

Recursion Stack:

O(h)

Balanced Tree:
O(log n)

Skewed Tree:
O(n)

------------------------------------------------

Optimal Approach

Use Postorder DFS.

Return height directly.

If subtree becomes unbalanced,
return -1.

TC = O(n)

------------------------------------------------

Pattern

Binary Tree
DFS
Height Calculation
Balanced Tree Check
*/