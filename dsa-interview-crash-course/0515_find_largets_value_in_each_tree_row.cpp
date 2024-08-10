#include <queue>
#include <vector>

#include "TreeNode.h"

class Solution {
   private:
    std::vector<int> maxVals;

   public:
    void dfs(TreeNode* root, int currDepth) {
        if (!root) return;

        if (static_cast<int>(maxVals.size()) <= currDepth) {
            maxVals.push_back(root->val);
        } else if (root->val > maxVals[currDepth]) {
            maxVals[currDepth] = root->val;
        }

        dfs(root->left, currDepth + 1);
        dfs(root->right, currDepth + 1);
        return;
    }

    void bfs(TreeNode* root) {
        std::queue<TreeNode*> currLevel;
        if (root) currLevel.push(root);

        int level = 0;
        while (!currLevel.empty()) {
            std::queue<TreeNode*> nextLevel;
            while (!currLevel.empty()) {
                if (static_cast<int>(maxVals.size()) <= level) {
                    maxVals.push_back(currLevel.front()->val);
                }
                if (currLevel.front()->val > maxVals[level]) {
                    maxVals[level] = currLevel.front()->val;
                }
                if (currLevel.front()->left)
                    nextLevel.push(currLevel.front()->left);
                if (currLevel.front()->right)
                    nextLevel.push(currLevel.front()->right);
                currLevel.pop();
            }
            currLevel = nextLevel;
            level++;
        }
    }

    std::vector<int> largestValues(TreeNode* root) {
        // dfs(root, 0);
        bfs(root);
        return maxVals;
    }
};
