#include <vector>

#include "TreeNode.h"

class Solution {
   public:
    TreeNode* buildTree(std::vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;

        int m = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = buildTree(nums, l, m - 1);
        root->right = buildTree(nums, m + 1, r);
        return root;
    }
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return buildTree(nums, 0, static_cast<int>(nums.size() - 1));
    }
};