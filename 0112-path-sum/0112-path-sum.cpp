class Solution {
public:
    void helper(TreeNode* root, int sum, bool& flag) {

        // Base Case
        if (root == NULL)
            return;

        /*
        Leaf Node

        If remaining sum equals
        current node value,

        then a valid root-to-leaf
        path exists.
        */
        if (root->left == NULL && root->right == NULL) {

            if (root->val == sum) {

                flag = true;
            }

            return;
        }

        /*
        Move downward.

        Reduce remaining sum
        by current node value.
        */
        helper(root->left, sum - root->val, flag);

        helper(root->right, sum - root->val, flag);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        bool flag = false;

        helper(root, targetSum, flag);

        return flag;
    }
};

/*
---------------- QUICK INTUITION ----------------

Need to check:

Is there any Root → Leaf path
whose sum equals targetSum?

------------------------------------------------

Idea

Instead of calculating
total sum at leaf,

keep subtracting node values
while moving downward.

------------------------------------------------

Example

          5
         / \
        4   8
       /
      11
     /  \
    7    2

target = 22

------------------------------------------------

At Node 5

Remaining Sum:

22 - 5

= 17

------------------------------------------------

At Node 4

Remaining Sum:

17 - 4

= 13

------------------------------------------------

At Node 11

Remaining Sum:

13 - 11

= 2

------------------------------------------------

At Leaf 2

Remaining Sum = 2

Node Value = 2

Match ✅

flag = true

------------------------------------------------

Dry Run

Tree:

      1
     / \
    2   3

target = 4

--------------------------------

At 1

Need = 4

Remaining:

3

--------------------------------

Go Left

At 2

Need = 3

Leaf

2 != 3

No Path

--------------------------------

Go Right

At 3

Need = 3

Leaf

3 == 3

flag = true

Answer = true

------------------------------------------------

Why Check Only Leaf?

Problem asks:

Root-to-Leaf Path Sum

Not root-to-any-node.

So sum must match
exactly at a leaf node.

------------------------------------------------

TC

Every node visited once.

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

Small Optimization

Instead of using flag reference,

helper can directly return bool.

Example:

return hasPath(left)
    || hasPath(right);

Cleaner interview solution.

------------------------------------------------

Pattern

Binary Tree
DFS
Recursion
Root-to-Leaf Path Sum
*/