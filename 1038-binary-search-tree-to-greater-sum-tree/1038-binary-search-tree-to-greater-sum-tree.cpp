class Solution {
public:
    /*
    Running sum of all nodes
    visited so far.

    Since we traverse from
    largest to smallest,

    this stores the sum of
    all greater (or equal)
    node values.
    */
    int sum = 0;

    // Reverse Inorder Traversal
    // Right -> Root -> Left
    void reverseInorder(TreeNode* root) {

        // Base Case
        if (root == NULL)
            return;

        /*
        Visit largest nodes first.
        */
        reverseInorder(root->right);

        /*
        Current node should contain:

        Original Value

        +

        Sum of all greater nodes.
        */
        root->val += sum;

        /*
        Update running sum
        for upcoming smaller nodes.
        */
        sum = root->val;

        /*
        Process smaller nodes.
        */
        reverseInorder(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {

        // Convert BST into GST
        reverseInorder(root);

        return root;
    }
};

/*
---------------- QUICK INTUITION ----------------

Need:

Every node becomes

Current Value

+

Sum of all greater nodes.

------------------------------------------------

Why Reverse Inorder?

Normal Inorder

Left -> Root -> Right

gives

Smallest → Largest

But we need

Largest → Smallest

So use

Right -> Root -> Left

------------------------------------------------

Example

BST

        4
       / \
      1   6
         / \
        5   7

------------------------------------------------

Reverse Inorder

7

↓

6

↓

5

↓

4

↓

1

------------------------------------------------

Running Sum

Initially

sum = 0

--------------------------------

Visit 7

7 + 0

= 7

sum = 7

--------------------------------

Visit 6

6 + 7

= 13

sum = 13

--------------------------------

Visit 5

5 + 13

= 18

sum = 18

--------------------------------

Visit 4

4 + 18

= 22

sum = 22

--------------------------------

Visit 1

1 + 22

= 23

sum = 23

------------------------------------------------

Final Tree Values

        22
       /  \
     23    13
          /  \
        18    7

------------------------------------------------

Why Update sum
after modifying node?

Suppose

Current node = 6

Greater nodes sum = 7

New Value

13

Now

all smaller nodes

should include

13

instead of original 6.

So

sum = root->val

------------------------------------------------

Dry Run

Tree

      2
     / \
    1   3

--------------------------------

Visit 3

sum = 0

3 + 0 = 3

sum = 3

--------------------------------

Visit 2

2 + 3 = 5

sum = 5

--------------------------------

Visit 1

1 + 5 = 6

sum = 6

--------------------------------

Final

      5
     / \
    6   3

------------------------------------------------

TC

Every node visited once.

O(n)

------------------------------------------------

SC

Recursion Stack

Balanced BST

O(log n)

Worst Case

O(n)

------------------------------------------------

Pattern

Binary Search Tree

Reverse Inorder Traversal

Running Prefix/Suffix Sum

Tree Modification
*/