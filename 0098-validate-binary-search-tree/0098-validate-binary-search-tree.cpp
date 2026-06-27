class Solution {
public:
    // Inorder Traversal
    void inorder(TreeNode* root, vector<int>& ans) {

        // Base Case
        if (root == NULL)
            return;

        // Visit left subtree
        inorder(root->left, ans);

        // Visit current node
        ans.push_back(root->val);

        // Visit right subtree
        inorder(root->right, ans);
    }

    bool isValidBST(TreeNode* root) {

        /*
        Store inorder traversal.
        */
        vector<int> ans;

        inorder(root, ans);

        /*
        Inorder traversal of a BST
        must be strictly increasing.

        If any element is
        smaller than or equal to
        previous element,

        then tree is not a BST.
        */
        for (int i = 1; i < ans.size(); i++) {

            if (ans[i] <= ans[i - 1])
                return false;
        }

        return true;
    }
};

/*
---------------- QUICK INTUITION ----------------

Important Property

Inorder Traversal of BST

always gives

Strictly Increasing Order.

------------------------------------------------

BST

        4
       / \
      2   6
     / \ / \
    1  3 5  7

Inorder

1 2 3 4 5 6 7

Strictly Increasing ✅

Valid BST

------------------------------------------------

Not a BST

        5
       / \
      1   4
         / \
        3   6

Inorder

1 5 3 4 6

5 > 3

Not Increasing ❌

Not a BST

------------------------------------------------

Why <= ?

BST requires

Left < Root < Right

Duplicates are NOT allowed.

Example

1 2 2 4

Since

2 <= 2

Tree is invalid.

------------------------------------------------

Dry Run

Tree

      2
     / \
    1   3

Inorder

[1,2,3]

--------------------------------

Compare

2 > 1

OK

--------------------------------

3 > 2

OK

Return true

------------------------------------------------

Another Example

      5
     / \
    1   4
       / \
      3   6

Inorder

[1,5,3,4,6]

--------------------------------

Compare

5 > 1

OK

--------------------------------

3 <= 5

Invalid

Return false

------------------------------------------------

TC

Inorder Traversal

O(n)

Checking array

O(n)

Total

O(n)

------------------------------------------------

SC

Vector stores
all node values.

O(n)

Recursion Stack

O(h)

Total

O(n)

------------------------------------------------

Optimal Approach

Instead of storing
entire inorder traversal,

keep track of
previous visited node/value
during inorder traversal.

Space:

O(h)

------------------------------------------------

Pattern

Binary Search Tree

Inorder Traversal

Tree Validation
*/