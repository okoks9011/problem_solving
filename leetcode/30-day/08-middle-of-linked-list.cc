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
    ListNode* middleNode(ListNode* head) {
        auto slow = head;
        auto fast = head;
        while (fast && fast->next) {
            assert(slow);
            slow = slow->next;

            assert(fast);
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }
        return slow;
    }
};
