# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        ahead = head
        for _ in range(n):
            ahead = ahead.next

        # if n == len(given-list)
        if not ahead:
            return head.next

        cur = head
        while ahead.next:
            cur = cur.next
            ahead = ahead.next
        cur.next = cur.next.next

        return head
