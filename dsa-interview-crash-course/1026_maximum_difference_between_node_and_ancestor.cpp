#include <climits>
#include <cmath>

#include "TreeNode.h"

class Solution {
   private:
    int max_diff = 0;

   public:
    // pre order traversal
    void dfs(TreeNode* root, int min_val, int max_val) {
        if (!root) return;

        min_val = std::min(min_val, root->val);
        max_val = std::max(max_val, root->val);

        max_diff = std::max(max_diff, max_val - min_val);
        dfs(root->left, min_val, max_val);
        dfs(root->right, min_val, max_val);
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, INT_MAX, INT_MIN);
        return max_diff;
    }
};