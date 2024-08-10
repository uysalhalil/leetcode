#include <vector>

#include "TreeNode.h"
class Solution {
   private:
    std::vector<std::vector<int>> order;
    void traverse_tree(TreeNode* root, int depth) {
        if (!root) return;

        if (order.size() <= depth) order.push_back({});
        order[depth].push_back(root->val);

        traverse_tree(root->left, depth + 1);
        traverse_tree(root->right, depth + 1);
    }

   public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        traverse_tree(root, 0);
        for (int i = 0; i < order.size(); ++i) {
            if (i % 2) reverse(order[i].begin(), order[i].end());
        }
        return order;
    }
};