#include "ListNode.h"

// O(N) Time and O(1) Space
class Solution {
   private:
    int getListLenght(ListNode* head) {
        int len = 0;
        ListNode* curr{head};
        while (curr) {
            curr = curr->next;
            ++len;
        }
        return len;
    }

   public:
    bool isPalindrome(ListNode* head) {
        int len = getListLenght(head);
        ListNode* head2{head};
        for (int i = 0; i < (len + 1) / 2; ++i) {
            head2 = head2->next;
        }

        ListNode* prev{nullptr};
        ListNode* head1{head};
        for (int i = 0; i < len / 2; ++i) {
            ListNode* next = head1->next;
            head1->next = prev;
            prev = head1;
            head1 = next;
        }
        head1 = prev;

        while (head1 && head2) {
            if (head1->val != head2->val) return false;
            head1 = head1->next;
            head2 = head2->next;
        }

        return true;
    }
};

// O(N) Time and O(N) Space
// class Solution {
// private:
//     vector<int> _vals;
//     void populateList(ListNode* head) {
//         ListNode* curr{head};
//         while (curr) {
//             _vals.push_back(curr->val);
//             curr = curr->next;
//         }
//     }
// public:
//     bool isPalindrome(ListNode* head) {
//         populateList(head);
//         int l = 0;
//         int r = _vals.size() - 1;
//         while (l < r) {
//             if (_vals[l] != _vals[r]) return false;
//             ++l;
//             --r;
//         }
//         return true;
//     }
// };
