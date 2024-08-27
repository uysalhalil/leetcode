#include <string>

#include "ListNode.h"

class Solution {
   public:
    std::string gameResult(ListNode* head) {
        int score = 0;
        ListNode* curr = head;
        while (curr) {
            if (curr->val > curr->next->val) {
                ++score;
            } else if (curr->val < curr->next->val) {
                --score;
            }
            curr = curr->next->next;  // this is true because problem ensures
                                      // that even number of nodes.
        }
        if (score > 0) {
            return "Even";
        } else if (score < 0) {
            return "Odd";
        } else {
            return "Tie";
        }
    }
};