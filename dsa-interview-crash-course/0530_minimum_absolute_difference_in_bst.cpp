#include <climits>
#include <cmath>
#include <vector>

#include "TreeNode.h"
class Solution {
   public:
    std::vector<int> serial;
    void serialize(TreeNode* root) {
        if (!root) return;

        serialize(root->left);
        serial.push_back(root->val);
        serialize(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        serialize(root);
        int min_val = INT_MAX;
        for (int i = 1; i < serial.size(); ++i) {
            min_val = std::min(min_val, serial[i] - serial[i - 1]);
        }
        return min_val;
    }
};