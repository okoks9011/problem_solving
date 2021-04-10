import heapq

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        min_pq = []
        for i, node in enumerate(lists):
            if node is None:
                continue
            heapq.heappush(min_pq, (node.val, i))

        root = ListNode()
        cur = root
        while min_pq:
            _, i = heapq.heappop(min_pq)
            cur.next = lists[i]
            lists[i] = lists[i].next
            if lists[i] is not None:
                heapq.heappush(min_pq, (lists[i].val, i))

            cur = cur.next
            cur.next = None
        return root.next
