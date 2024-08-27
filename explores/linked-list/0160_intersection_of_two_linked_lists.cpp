#include "ListNode.h"

class Solution {
   private:
    int getLenght(ListNode* head) {
        int len{0};
        ListNode* curr{head};
        while (curr) {
            curr = curr->next;
            ++len;
        }
        return len;
    }

    void moveCurrNode(ListNode*& curr, int n) {
        while (n) {
            curr = curr->next;
            --n;
        }
    }

   public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA{getLenght(headA)};
        int lenB{getLenght(headB)};

        ListNode* currA{headA};
        ListNode* currB{headB};
        int diff{0};
        if (lenA > lenB) {
            diff = lenA - lenB;
            moveCurrNode(currA, diff);
        } else {
            diff = lenB - lenA;
            moveCurrNode(currB, diff);
        }

        while (currA && currB) {
            if (currA == currB) return currA;
            currA = currA->next;
            currB = currB->next;
        }
        return nullptr;
    }
};