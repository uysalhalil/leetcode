class Node {
   public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
   private:
    Node* first = nullptr;
    Node* last = nullptr;

    void solve(Node* root) {
        if (root) {
            solve(root->left);

            if (!first) {
                first = root;
            } else {
                last->right = root;
                root->left = last;
            }
            last = root;
            solve(root->right);
        }
    }

   public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        solve(root);
        first->left = last;
        last->right = first;
        return first;
    }
};