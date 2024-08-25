
#include <stack>

// Definition for a Node.
class Node {
   public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
   public:
    Node* flatten(Node* head) {
        std::stack<Node*> st;
        Node* dmyHead = new Node(0);
        dmyHead->next = head;
        Node* curr{dmyHead};
        Node* prev{nullptr};

        while (curr) {
            prev = curr;
            curr = curr->next;
            if (curr && curr->child) {
                if (curr->next) {
                    st.push(curr->next);
                }
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }

            if (!curr && !st.empty()) {
                curr = st.top();
                prev->next = curr;
                curr->prev = prev;
                st.pop();
            }
        }
        return dmyHead->next;
    }
};
