# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def add_two_numbers_with_carry(self, l1: ListNode, l2: ListNode, carry: int) -> ListNode:
        if l1 is None and l2 is None:
            if carry > 0:
                return ListNode(val=carry)
            else:
                return None

        val = 0
        l1_next = None
        if l1:
            val += l1.val
            l1_next = l1.next
        l2_next = None
        if l2:
            val += l2.val
            l2_next = l2.next
        val += carry

        return ListNode(
            val=val % 10,
            next=self.add_two_numbers_with_carry(l1_next, l2_next, val // 10)
        )


    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        return self.add_two_numbers_with_carry(l1, l2, 0)
