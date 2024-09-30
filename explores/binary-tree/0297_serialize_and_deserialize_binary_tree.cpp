#include <new>
#include <string>

#include "TreeNode.h"

class Codec {
    size_t colon{0};
    int currentPos = 0;
    std::string subtree{""};

   public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        if (!root) {
            return "{nullptr,}";
        }

        std::string encodedData{"{" + std::to_string(root->val)};
        std::string leftEncodedData = serialize(root->left);
        std::string rightEncodedData = serialize(root->right);

        encodedData = encodedData + ",left:" + leftEncodedData +
                      ",right:" + rightEncodedData + "}";
        return encodedData;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        size_t pos = data.find(",", currentPos);
        std::string val{data.substr(currentPos + 1, pos - currentPos - 1)};
        if (val.compare("nullptr") == 0) {
            currentPos = pos + 1;
            while (currentPos < data.size() && data[currentPos] == '}') {
                ++currentPos;  // move one char for closing curly brace
            }

            if (currentPos < data.size()) {
                ++currentPos;  // move one char for comma
            }
            return nullptr;
        }
        currentPos = pos + 1;
        TreeNode* t = new TreeNode(stoi(val));

        // left subtree
        colon = data.find(":", currentPos);
        currentPos = colon + 1;
        t->left = deserialize(data);

        // right subtree
        colon = data.find(":", currentPos);
        currentPos = colon + 1;
        t->right = deserialize(data);

        return t;
    }
};