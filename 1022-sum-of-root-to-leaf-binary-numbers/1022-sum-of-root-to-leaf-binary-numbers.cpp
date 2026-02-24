class Solution {
public:

    // DFS to collect all root-to-leaf binary paths
    void dfs(TreeNode* root, string path, vector<string>& paths) {
        if(!root) return;

        // Current node ka bit add karo
        path += to_string(root->val);

        // Agar leaf node hai
        if(!root->left && !root->right) {
            paths.push_back(path);
            return;
        }

        // Left aur right subtree explore karo
        dfs(root->left, path, paths);
        dfs(root->right, path, paths);
    }

    // Right to Left binary to decimal conversion
    int binaryToDecimal(string s) {
        int n = s.size();
        int power = 0;
        int num = 0;

        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '1') {
                num += (1 << power);   // 2^power
            }
            power++;
        }

        return num;
    }

    int sumRootToLeaf(TreeNode* root) {
        vector<string> paths;

        // Step 1: Collect all binary paths
        dfs(root, "", paths);

        int total = 0;

        // Step 2: Convert each path to decimal
        for(string s : paths) {
            total += binaryToDecimal(s);
        }

        return total;
    }
};