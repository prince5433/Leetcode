class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        // Final answer
        vector<vector<int>> ans;

        // Empty tree
        if(root == NULL)
            return ans;

        /*
        Level numbering:

        Level 1 -> Left to Right
        Level 2 -> Right to Left
        Level 3 -> Left to Right
        ...
        */
        int level = 1;

        // Standard BFS queue
        queue<TreeNode*> qu;
        qu.push(root);

        while(!qu.empty()) {

            // Stores current level nodes
            vector<int> v;

            // Number of nodes at current level
            int sz = qu.size();

            for(int i = 1; i <= sz; i++) {

                // Get front node
                TreeNode* node = qu.front();
                qu.pop();

                // Store node value
                v.push_back(node->val);

                // Push left child
                if(node->left)
                    qu.push(node->left);

                // Push right child
                if(node->right)
                    qu.push(node->right);
            }

            /*
            For Zigzag:

            Even levels:
            Right -> Left

            So reverse current level.
            */
            if(level % 2 == 0) {
                reverse(v.begin(), v.end());
            }

            // Store current level
            ans.push_back(v);

            // Move to next level
            level++;
        }

        return ans;
    }
};

/*
---------------- QUICK INTUITION ----------------

Normal BFS gives:

Level 1 -> [1]
Level 2 -> [2,3]
Level 3 -> [4,5,6,7]

For Zigzag:

Level 1 -> [1]
Level 2 -> [3,2]
Level 3 -> [4,5,6,7]

So we perform normal BFS
and simply reverse even levels.

------------------------------------------------

Example:

        1
       / \
      2   3
     / \ / \
    4 5 6 7

--------------------------------

Level 1:

[1]

--------------------------------

Level 2:

[2,3]

reverse

[3,2]

--------------------------------

Level 3:

[4,5,6,7]

--------------------------------

Answer:

[
 [1],
 [3,2],
 [4,5,6,7]
]

------------------------------------------------

TC:

BFS traversal -> O(n)

Reverse operations overall -> O(n)

Total:
O(n)

------------------------------------------------

SC:

Queue + Answer

O(n)

------------------------------------------------

Pattern:

Binary Tree
BFS
Queue
Zigzag Level Order Traversal
*/