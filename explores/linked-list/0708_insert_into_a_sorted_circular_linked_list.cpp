
// Definition for a Node.
class Node {
   public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
   public:
    Node* insert(Node* head, int insertVal) {
        Node* insertNode = new Node(insertVal);
        if (!head) {  // empty list
            insertNode->next = insertNode;
            return insertNode;
        } else if (head->next == head) {  // single node list
            head->next = insertNode;
            insertNode->next = head;
            return head;
        }

        Node* node{head};
        int seenHead = 0;
        while (seenHead < 2 && node->next && node->next->val >= node->val) {
            if (node == head)
                ++seenHead;  // head check is to avoid infinite loop for equal
                             // list
            node = node->next;
        }

        Node* maxNode{node};
        Node* minNode{node->next};

        if (insertNode->val > maxNode->val || insertNode->val < minNode->val) {
            maxNode->next = insertNode;
            insertNode->next = minNode;
        } else {
            Node* currNode = minNode;
            while (currNode->next != minNode) {
                if (currNode->val <= insertNode->val &&
                    insertNode->val <= currNode->next->val) {
                    insertNode->next = currNode->next;
                    currNode->next = insertNode;
                    return head;
                }
                currNode = currNode->next;
            }
        }

        return head;
    }
};