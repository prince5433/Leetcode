class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        /*
        Base Case

        Empty position found.

        Create new node here.
        */
        if (root == NULL)
            root = new TreeNode(val);

        /*
        Current node value
        is greater than val.

        Insert into left subtree.
        */
        else if (root->val > val) {

            /*
            Left child empty.

            Insert directly.
            */
            if (root->left == NULL)
                root->left = new TreeNode(val);

            /*
            Otherwise keep
            searching in left subtree.
            */
            else
                insertIntoBST(root->left, val);
        }

        /*
        Current node value
        is smaller than val.

        Insert into right subtree.
        */
        else {

            /*
            Right child empty.

            Insert directly.
            */
            if (root->right == NULL)
                root->right = new TreeNode(val);

            /*
            Otherwise continue
            searching in right subtree.
            */
            else
                insertIntoBST(root->right, val);
        }

        // Return original root
        return root;
    }
};

/*
---------------- QUICK INTUITION ----------------

BST Property

Left < Root < Right

While inserting,

keep moving until
an empty position
(NULL) is found.

Insert new node there.

------------------------------------------------

Example

Insert = 5

Initial Tree

        4
       / \
      2   7

--------------------------------

Current = 4

5 > 4

Go Right

--------------------------------

Current = 7

5 < 7

Go Left

--------------------------------

Left is NULL

Insert 5

Final Tree

        4
       / \
      2   7
         /
        5

------------------------------------------------

Another Example

Insert = 1

Tree

        4
       / \
      2   7

--------------------------------

4 > 1

Go Left

--------------------------------

2 > 1

Go Left

--------------------------------

NULL

Insert 1

Tree

        4
       / \
      2   7
     /
    1

------------------------------------------------

Dry Run

Insert = 6

Tree

      5
       \
        8
       /
      7

--------------------------------

5 < 6

Go Right

--------------------------------

8 > 6

Go Left

--------------------------------

7 > 6

Go Left

--------------------------------

NULL

Insert 6

------------------------------------------------

Why only one recursive call?

BST property tells us
exactly where the value
should be inserted.

So we never explore
both subtrees.

------------------------------------------------

TC

Balanced BST

O(log n)

--------------------------------

Worst Case
(Skewed Tree)

O(n)

------------------------------------------------

SC

Recursion Stack

Balanced:

O(log n)

Skewed:

O(n)

------------------------------------------------

Cleaner Recursive Version

Instead of checking
left/right == NULL,

we can simply write:

root->left = insertIntoBST(root->left, val);

or

root->right = insertIntoBST(root->right, val);

This is the version
most interviewers prefer.

------------------------------------------------

Pattern

Binary Search Tree

Recursion

BST Insertion
*/