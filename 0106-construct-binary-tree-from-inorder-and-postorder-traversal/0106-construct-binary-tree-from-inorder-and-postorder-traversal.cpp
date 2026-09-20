class Solution {
public:
    // Recursive function to build tree
    TreeNode* build(vector<int>& in, int inlo, int inhi, vector<int>& post,
                    int postlo, int posthi) {

        /*
        Base Case:

        No elements available
        to build a tree.
        */
        if (inlo > inhi)
            return NULL;

        /*
        Last element of postorder
        is always the root.

        Postorder:

        Left Right Root
        */
        TreeNode* root = new TreeNode(post[posthi]);

        /*
        Single node.

        Leaf node.
        */
        if (inlo == inhi)
            return root;

        /*
        Find root position
        inside inorder array.
        */
        int i = inlo;

        while (i <= inhi) {

            if (in[i] == post[posthi])
                break;

            i++;
        }

        // Number of nodes in left subtree
        int lc = i - inlo;

        // Number of nodes in right subtree
        int rc = inhi - i;

        /*
        Build Left Subtree

        Inorder:

        inlo ... i-1

        Postorder:

        postlo ... postlo+lc-1
        */
        root->left = build(in, inlo, i - 1, post, postlo, postlo + lc - 1);

        /*
        Build Right Subtree

        Inorder:

        i+1 ... inhi

        Postorder:

        postlo+lc ... posthi-1
        */
        root->right = build(in, i + 1, inhi, post, postlo + lc, posthi - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {

        int n = in.size();

        return build(in, 0, n - 1, post, 0, n - 1);
    }
};

/*
---------------- QUICK INTUITION ----------------

Important Property

Inorder:

Left Root Right

Postorder:

Left Right Root

------------------------------------------------

Key Observation

Last element of Postorder
is always the Root.

------------------------------------------------

Example

Inorder:

[9,3,15,20,7]

Postorder:

[9,15,7,20,3]

------------------------------------------------

Step 1

Root = 3

(last element of postorder)

Tree:

      3

------------------------------------------------

Step 2

Find 3 in inorder

[9, 3, 15,20,7]

Left Part:

[9]

Right Part:

[15,20,7]

------------------------------------------------

Step 3

Left subtree size

lc = 1

Right subtree size

rc = 3

------------------------------------------------

Step 4

Split postorder

Postorder:

[9,15,7,20,3]

Last element = root

Before root:

[9,15,7,20]

--------------------------------

First lc elements

[9]

belong to Left Subtree

--------------------------------

Remaining

[15,7,20]

belong to Right Subtree

------------------------------------------------

Recursive Calls

Left:

Inorder:
[9]

Postorder:
[9]

--------------------------------

Right:

Inorder:
[15,20,7]

Postorder:
[15,7,20]

------------------------------------------------

Final Tree

        3
       / \
      9   20
         /  \
        15   7

------------------------------------------------

Why lc Needed?

lc tells exactly
how many nodes belong
to left subtree.

Using that count,
we split postorder correctly.

------------------------------------------------

Dry Run

Root = 3

lc = 1

--------------------------------

Left:

build([9],[9])

returns node 9

--------------------------------

Right:

Root = 20

Inorder:

[15,20,7]

Left:

15

Right:

7

Build recursively.

------------------------------------------------

TC

Current Code:

Searching root in inorder
takes O(n) every call.

Worst Case:

O(n²)

------------------------------------------------

Optimization

Store:

value -> inorder index

in HashMap.

Then lookup O(1).

Total:

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

Binary Tree Construction
Recursion
Divide & Conquer
Inorder + Postorder
*/