#include "TreeNode.h"

class Solution {
   private:
    int rangeSum{0};
    void dfs(TreeNode* root, const int& low, const int& high) {
        if (!root) return;

        if (low <= root->val && root->val <= high) rangeSum += root->val;

        if (low <= root->val) dfs(root->left, low, high);
        if (root->val <= high) dfs(root->right, low, high);
    }

   public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root, low, high);
        return rangeSum;
    }
};