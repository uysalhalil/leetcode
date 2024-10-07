#include <cmath>

#include "TreeNode.h"

class Solution {
   private:
    int _minVal{0};
    int _maxVal{0};
    TreeNode* findLowestCommonAncestor(TreeNode* root, TreeNode* p,
                                       TreeNode* q) {
        if (!root)
            return nullptr;  // just in case edge (actually constraints makes
                             // this check void)
        if (root->val >= _minVal && root->val <= _maxVal) return root;
        if (root->val < _minVal)
            return findLowestCommonAncestor(root->right, p, q);
        else
            return findLowestCommonAncestor(root->left, p, q);
    }

   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        _minVal = std::min(p->val, q->val);
        _maxVal = std::max(p->val, q->val);
        return findLowestCommonAncestor(root, p, q);
    }
};