class Solution {
public:
    // Returns height of tree
    int levels(TreeNode* root) {

        /*
        Height of empty tree = 0
        */
        if (root == NULL)
            return 0;

        /*
        Height =

        1 +
        maximum height of children
        */
        return 1 + max(levels(root->left), levels(root->right));
    }

    void helper(TreeNode* root, int& maxDia) {

        if (root == NULL)
            return;

        /*
        Diameter passing through
        current node.

        left height
        +
        right height
        */
        int dia = levels(root->left) + levels(root->right);

        // Update global answer
        maxDia = max(maxDia, dia);

        // Check left subtree
        helper(root->left, maxDia);

        // Check right subtree
        helper(root->right, maxDia);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        int maxDia = 0;

        helper(root, maxDia);

        return maxDia;
    }
};

/*
---------------- QUICK INTUITION ----------------

Diameter:

Maximum number of edges
between any two nodes.

------------------------------------------------

Key Observation

For every node:

Possible diameter through node =

height(left)
+
height(right)

Because longest path may go:

left subtree
     ↓
 current node
     ↓
right subtree

------------------------------------------------

Example:

        1
       / \
      2   3
     / \
    4   5

At node 2:

left height = 1
right height = 1

dia = 2

--------------------------------

At node 1:

left height = 2
right height = 1

dia = 3

Answer = 3

------------------------------------------------

Dry Run

Node 4:

dia = 0

Node 5:

dia = 0

Node 2:

dia = 1+1 = 2

Node 3:

dia = 0

Node 1:

dia = 2+1 = 3

maxDia = 3

------------------------------------------------

IMPORTANT

This solution is NOT Optimal.

Why?

For every node,
you are again calling levels().

Height gets recalculated
many times.

------------------------------------------------

TC

levels() = O(n)

Called for every node.

Total:

O(n²)

------------------------------------------------

SC

Recursion Stack:

O(h)

Worst:

O(n)

Balanced Tree:

O(log n)

------------------------------------------------

Optimization

Compute:

height + diameter

in same DFS.

Then:

TC = O(n)

Pattern:

Postorder DFS
Tree DP

------------------------------------------------

Pattern Used Here

Binary Tree
DFS
Brute Force Diameter
*/