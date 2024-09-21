#include "TreeNode.h"

class Solution {
   private:
    int _nsub{0};
    bool helper(TreeNode* root) {
        if (!root) return true;

        bool isLeftUnival = helper(root->left);
        bool isRightUnival = helper(root->right);

        if (isLeftUnival && isRightUnival) {
            if (root->left && root->val != root->left->val) return false;
            if (root->right && root->val != root->right->val) return false;
            ++_nsub;
            return true;
        }
        return false;
    }

   public:
    int countUnivalSubtrees(TreeNode* root) {
        helper(root);
        return _nsub;
    }
};