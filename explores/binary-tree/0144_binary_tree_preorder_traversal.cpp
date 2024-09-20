#include <vector>

#include "TreeNode.h"

// class Solution {
// std::vector<int> _preorder;
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         if (!root) return _preorder;
//         _preorder.push_back(root->val);
//         preorderTraversal(root->left);
//         preorderTraversal(root->right);
//         return _preorder;
//     }
// };

class Solution {
   private:
    std::vector<int> _res;
    void traverse(TreeNode* root) {
        if (!root) return;
        _res.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }

   public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return _res;
    }
};