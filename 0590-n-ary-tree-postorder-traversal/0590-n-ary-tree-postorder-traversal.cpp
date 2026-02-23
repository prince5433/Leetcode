/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;

    // DFS function to perform postorder traversal on N-ary tree
    void dfs(Node* root) {
        if (root == NULL) return;                 // Base case: null node → no work

        // First traverse all children of the current node
        for (auto children : root->children) {
            dfs(children);                        // Recursively visit each child
        }

        ans.push_back(root->val);                 // After children → push current node (postorder)
    }

    vector<int> postorder(Node* root) {
        dfs(root);                                // Start DFS from the root
        return ans;                               // Final traversal result
    }
};
