#include <climits>
#include <vector>

#include "TreeNode.h"
class Solution {
   private:
    bool inorder_traversal(TreeNode* root, double left_range,
                           double right_range) {
        if (!root) return true;
        if (left_range >= root->val || right_range <= root->val) return false;

        return inorder_traversal(root->left, left_range, root->val) &&
               inorder_traversal(root->right, root->val, right_range);
    }

   public:
    bool isValidBST(TreeNode* root) {
        // initial
        double left_range = static_cast<double>(INT_MIN) - 1;
        double right_range = static_cast<double>(INT_MAX) + 1;
        return inorder_traversal(root, left_range, right_range);
    }
};

/*class Solution {
private:
    std::vector<int> vals;
    void inorder_traversal(TreeNode* root) {
        if (!root) return;
        inorder_traversal(root->left);
        vals.push_back(root->val);
        inorder_traversal(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        // initial
        inorder_traversal(root);
        int pre = vals[0];
        for (int i = 1; i < vals.size(); ++i) {
            if (vals[i] <= pre) return false;
            pre = vals[i];
        }
        return true;
    }
};*/