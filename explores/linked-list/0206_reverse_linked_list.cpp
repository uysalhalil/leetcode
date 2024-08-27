#include "ListNode.h"

class Solution {
   private:
    ListNode* reverseRecursion(ListNode* prev, ListNode* curr) {
        if (!curr) {
            return prev;
        }

        ListNode* next = curr->next;
        curr->next = prev;
        return reverseRecursion(curr, next);
    }

   public:
    ListNode* reverseList(ListNode* head) {
        // ListNode* prev = nullptr;
        // ListNode* curr = head;

        // while (curr) {
        //     ListNode* next = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = next;
        // }
        // return prev;
        return reverseRecursion(nullptr, head);
    }
};