#include "../utils.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int longest = 0;
        function<int(TreeNode*)> dfs = [&dfs, &longest](TreeNode* root) {
            if (root == nullptr) return 0;
            int leftDepth = dfs(root->left);
            int rightDepth = dfs(root->right);
            longest = max(longest, leftDepth + rightDepth);
            return 1 + max(leftDepth, rightDepth);
        };
        dfs(root);
        return longest;
    }
};
