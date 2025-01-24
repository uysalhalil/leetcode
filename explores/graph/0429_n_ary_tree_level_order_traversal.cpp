#include <vector>

// Definition for a Node.
class Node {
   public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
   public:
    std::vector<std::vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        std::vector<Node*> currLevel{root};
        std::vector<std::vector<int>> treeVals{{root->val}};
        while (!currLevel.empty()) {
            treeVals.push_back({});
            std::vector<Node*> nextLevel;
            for (Node* levelNode : currLevel) {
                if (!levelNode->children.empty()) {
                    for (Node* child : levelNode->children) {
                        treeVals.back().push_back(child->val);
                        nextLevel.push_back(child);
                    }
                }
            }
            currLevel = nextLevel;
        }

        if (treeVals.back().empty()) treeVals.pop_back();
        return treeVals;
    }
};