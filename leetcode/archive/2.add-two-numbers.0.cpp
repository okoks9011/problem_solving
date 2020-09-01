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
    ListNode* addWithCarry(ListNode* l1, ListNode* l2, int carry) {
        if (l1 == nullptr && l2 == nullptr) {
            if (carry)
                return new ListNode(carry);
            else
                return nullptr;
        }
        if (l1 == nullptr)
            l1 = new ListNode(0);
        if (l2 == nullptr)
            l2 = new ListNode(0);

        int cur_val = l1->val + l2->val + carry;
        auto rest = addWithCarry(l1->next, l2->next, cur_val/10);

        ListNode* result = new ListNode(cur_val%10);
        result->next = rest;
        return result;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addWithCarry(l1, l2, 0);
    }
};
