#include "TreeNode.h"

class Solution {
   public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // leaf
        if (!root->left && !root->right) return root->val == targetSum;

        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};