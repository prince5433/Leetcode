class Solution {
public:
    // Builds a height-balanced BST
    // from sorted array
    TreeNode* helper(vector<int>& nums, int lo, int hi) {

        /*
        Base Case

        No elements left
        to create a node.
        */
        if (lo > hi)
            return NULL;

        /*
        Middle element becomes
        the root.

        Choosing middle keeps
        the BST balanced.
        */
        int mid = lo + (hi - lo) / 2;

        // Create root node
        TreeNode* root = new TreeNode(nums[mid]);

        /*
        Left half of array

        becomes

        Left subtree.
        */
        root->left = helper(nums, lo, mid - 1);

        /*
        Right half of array

        becomes

        Right subtree.
        */
        root->right = helper(nums, mid + 1, hi);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {

        int n = nums.size();

        /*
        Build BST using
        entire array.
        */
        return helper(nums, 0, n - 1);
    }
};

/*
---------------- QUICK INTUITION ----------------

Given

Sorted Array

Need

Height Balanced BST

------------------------------------------------

Main Idea

Always choose

Middle Element

as root.

Why?

Because

equal number of elements
go to left and right.

Tree remains balanced.

------------------------------------------------

Example

nums

[1,2,3,4,5,6,7]

--------------------------------

Middle

4

Root

        4

--------------------------------

Left Half

[1,2,3]

Right Half

[5,6,7]

--------------------------------

Repeat

Left

Middle = 2

Right

Middle = 6

Tree

          4
        /   \
       2     6
      / \   / \
     1  3  5  7

------------------------------------------------

Dry Run

nums

[-10,-3,0,5,9]

--------------------------------

lo = 0

hi = 4

mid = 2

Root = 0

--------------------------------

Left

[-10,-3]

mid = 0

Root = -10

Right Child = -3

--------------------------------

Right

[5,9]

mid = 3

Root = 5

Right Child = 9

------------------------------------------------

Final Tree

         0
       /   \
    -10     5
       \      \
       -3      9

------------------------------------------------

Why Middle?

If first element
is always chosen,

tree becomes skewed.

Example

1 2 3 4 5

↓

1
 \
  2
   \
    3
     \
      4
       \
        5

Height = O(n)

--------------------------------

Choosing middle

keeps height

≈ log n

------------------------------------------------

TC

Every element
creates one node.

O(n)

------------------------------------------------

SC

Recursion Stack

Balanced Tree

O(log n)

Worst Case

O(log n)

(Because tree remains balanced)

------------------------------------------------

Pattern

Binary Search Tree

Divide & Conquer

Recursion

Sorted Array → BST
*/