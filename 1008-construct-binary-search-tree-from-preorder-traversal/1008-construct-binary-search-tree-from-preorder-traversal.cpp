class Solution {
public:
    // Insert one value into BST
    void insert(TreeNode* root, int val) {

        /*
        This case will never occur
        in this solution because

        insert() is always called
        with a valid root.
        */
        if (root == NULL) {

            root = new TreeNode(val);

            return;
        }

        /*
        Current value is greater.

        Insert into left subtree.
        */
        if (root->val > val) {

            /*
            Empty position found.

            Create new node.
            */
            if (root->left == NULL) {

                root->left = new TreeNode(val);
            }

            /*
            Otherwise continue
            searching.
            */
            else {

                insert(root->left, val);
            }
        }

        /*
        Current value is smaller
        (or equal).

        Insert into right subtree.
        */
        else {

            /*
            Empty position found.

            Create new node.
            */
            if (root->right == NULL) {

                root->right = new TreeNode(val);
            }

            /*
            Continue searching.
            */
            else {

                insert(root->right, val);
            }
        }
    }

    TreeNode* bstFromPreorder(vector<int>& pre) {

        /*
        First preorder element
        is always the root.
        */
        TreeNode* root = new TreeNode(pre[0]);

        /*
        Insert all remaining
        values one by one.
        */
        for (int i = 1; i < pre.size(); i++) {

            insert(root, pre[i]);
        }

        return root;
    }
};

/*
---------------- QUICK INTUITION ----------------

Preorder

Root Left Right

First element is always
the root of BST.

------------------------------------------------

Idea

Create root

Then insert every
remaining element
using normal BST insertion.

------------------------------------------------

Example

Preorder

[8,5,1,7,10,12]

--------------------------------

Step 1

Root

8

--------------------------------

Insert 5

5 < 8

        8
       /
      5

--------------------------------

Insert 1

1 < 8

1 < 5

        8
       /
      5
     /
    1

--------------------------------

Insert 7

7 < 8

7 > 5

        8
       /
      5
     / \
    1   7

--------------------------------

Insert 10

10 > 8

        8
       / \
      5   10
     / \
    1   7

--------------------------------

Insert 12

12 > 8

12 > 10

        8
       / \
      5   10
     / \    \
    1   7    12

------------------------------------------------

Final BST

        8
       / \
      5   10
     / \    \
    1   7    12

------------------------------------------------

Dry Run

Current Insert = 7

At 8

7 < 8

Go Left

--------------------------------

At 5

7 > 5

Go Right

--------------------------------

Right NULL

Create node 7

Done.

------------------------------------------------

Why BST Insert Works?

Every inserted value
automatically reaches
its correct position
because BST property
is maintained.

------------------------------------------------

TC

Each insertion

Balanced BST

O(log n)

Total

O(n log n)

--------------------------------

Worst Case

Skewed BST

Each insertion

O(n)

Total

O(n²)

------------------------------------------------

SC

Recursion Stack

Balanced

O(log n)

Worst

O(n)

------------------------------------------------

Optimal Approach

Using preorder bounds
(min/max recursion)

TC

O(n)

SC

O(h)

------------------------------------------------

Pattern

Binary Search Tree

BST Insertion

Preorder Construction
*/