import random


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def __init__(self, head: ListNode):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        """
        self.head = head

        length = 0
        while head is not None:
            length += 1
            head = head.next
        self.length = length

    def getRandom(self) -> int:
        """
        Returns a random node's value.
        """
        cnt = random.randrange(self.length)
        cur = self.head
        for _ in range(cnt):
            if cur.next is not None:
                cur = cur.next
            else:
                cur = self.head
        return cur.val


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
