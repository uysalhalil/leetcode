#include <climits>
#include <cmath>

#include "TreeNode.h"
class Solution {
   private:
    double minDiff{INT_MAX};
    int minDiffValue{INT_MAX};

   public:
    void dfs(TreeNode* root, double target) {
        if (!root) {
            return;
        }

        double currDiff = std::abs(static_cast<double>(root->val) - target);
        if (currDiff <= minDiff) {
            minDiffValue = currDiff == minDiff
                               ? std::min(root->val, minDiffValue)
                               : root->val;
            minDiff = currDiff;
        }

        dfs(root->left, target);
        dfs(root->right, target);
        return;
    }
    int closestValue(TreeNode* root, double target) {
        dfs(root, target);
        return minDiffValue;
    }
};