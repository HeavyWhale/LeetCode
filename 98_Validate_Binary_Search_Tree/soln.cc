#include "../utils.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        function<bool(TreeNode*,TreeNode*,TreeNode*)> validateInRange = 
        [&](TreeNode* root, TreeNode* lo, TreeNode* hi) {
            if (root == nullptr) return true;
            if ((lo != nullptr && root->val <= lo->val) || (hi != nullptr && root->val >= hi->val))
                return false;
            return validateInRange(root->right, root, hi) && validateInRange(root->left, lo, root);
        };

        return validateInRange(root, nullptr, nullptr);
    }
};
