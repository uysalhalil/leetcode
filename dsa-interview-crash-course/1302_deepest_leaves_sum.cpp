#include <cmath>

#include "TreeNode.h"

class Solution {
   private:
    int maxDepth = 0;
    int leavesSum = 0;

   public:
    void dfs(TreeNode* root, int currDepth) {
        if (!root) return;
        if (!root->left && !root->right) {
            if (currDepth > maxDepth) {
                leavesSum = root->val;
            } else if (currDepth == maxDepth) {
                leavesSum += root->val;
            }
        }
        maxDepth = std::max(maxDepth, currDepth);
        dfs(root->left, currDepth + 1);
        dfs(root->right, currDepth + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return leavesSum;
    }
};