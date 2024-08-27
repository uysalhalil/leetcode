#include "ListNode.h"

class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* currNode = dummyHead;
        while (currNode && currNode->next) {
            if (currNode->next->val == val) {
                ListNode* nodeToDelete = new ListNode(-1);
                nodeToDelete = currNode->next;
                currNode->next = nodeToDelete->next;
                nodeToDelete->next = nullptr;
                delete nodeToDelete;
            } else {
                currNode = currNode->next;
            }
        }
        head = dummyHead->next;
        dummyHead->next = nullptr;
        delete dummyHead;
        return head;
    }
};