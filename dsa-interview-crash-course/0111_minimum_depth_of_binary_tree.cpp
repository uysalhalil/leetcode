#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        // If only one of child is non-null, then go into that recursion.
        if (!root->left) {
            return 1 + minDepth(root->right);
        } else if (!root->right) {
            return 1 + minDepth(root->left);
        }

        // Both children are non-null, hence call for both children.
        return 1 + std::min(minDepth(root->left), minDepth(root->right));
    }
};