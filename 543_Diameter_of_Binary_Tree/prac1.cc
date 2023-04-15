#include "../utils.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int longest = 0;
        // Returns the height of (sub)tree at `root`
        // Note: height of a leaf node is 0, height of the null child of a leaf node is -1
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == nullptr) return -1;
            int leftHeight = dfs(root->left),
                rightHeight = dfs(root->right);
            // Update longest path at current level, adding two edges to left and right child
            longest = max(longest, leftHeight + rightHeight + 2);
            return 1 + max(leftHeight, rightHeight);
        };
        dfs(root);
        return longest;
    }
};
