#include <climits>
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
   private:
    int n = 0;

   public:
    void nGoodNodes(TreeNode *root, int maxValue) {
        if (!root) return;

        if (root->val >= maxValue) ++n;

        nGoodNodes(root->left, std::max(maxValue, root->val));
        nGoodNodes(root->right, std::max(maxValue, root->val));
    }
    int goodNodes(TreeNode *root) {
        nGoodNodes(root, INT_MIN);
        return n;
    }
};