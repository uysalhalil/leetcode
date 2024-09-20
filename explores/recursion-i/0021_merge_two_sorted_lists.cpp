struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* prev) {
        if (l1 == nullptr || l2 == nullptr) {
            return prev->next = l1 == nullptr ? l2 : l1;
        }

        if (l1->val <= l2->val) {
            prev->next = l1;
            l1 = l1->next;
        } else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
        return merge(l1, l2, prev);
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* prev = new ListNode(-101);
        merge(list1, list2, prev);
        return prev->next;
    }
};