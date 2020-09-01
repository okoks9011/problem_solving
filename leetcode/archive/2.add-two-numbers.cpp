/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode* addList(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        auto rest = addList(l1->next, l2->next);
        ListNode* result = new ListNode(l1->val+l2->val);
        result->next = rest;
        return result;
    }

    void correctList(ListNode* l, int carry) {
        if (l == nullptr)
            return;

        l->val += carry;
        if ((l->val / 10) && l->next == nullptr)
            l->next = new ListNode(0);

        correctList(l->next, l->val/10);
        l->val %= 10;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto result = addList(l1, l2);
        correctList(result, 0);
        return result;
    }
};
