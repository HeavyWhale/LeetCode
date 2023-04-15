#include "../utils.h"

class Solution {
public:
    // Longest leaf-to-leaf path
    int diameterOfBinaryTree(TreeNode* root) {
        return optimized(root);
    }

private:
    int intuitive(TreeNode* root) {
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

    int optimized(TreeNode* root) {
        if (root == nullptr) return 0;
        int longest = 0;
        // Note: we define the height of a leaf node to be 1, and that of a null child is 0,
        //       this natually results in the length of a longest path passing through root
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == nullptr) return 0;
            int leftHeight = dfs(root->left);
            int rightHeight = dfs(root->right);
            longest = max(longest, leftHeight + rightHeight); // record longest path at current level
            return 1 + max(leftHeight, rightHeight);
        };
        dfs(root);
        return longest;
    }
};
