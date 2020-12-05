# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import namedtuple

Elem = namedtuple('Elem', ['with_cur', 'without_cur'])


class Solution:
    def get_max_money(self, cur):
        if cur is None:
            return Elem(0, 0)

        left = self.get_max_money(cur.left)
        right = self.get_max_money(cur.right)
        with_cur = cur.val + left.without_cur + right.without_cur
        without_cur = max(left) + max(right)
        return Elem(with_cur, without_cur)

    def rob(self, root: TreeNode) -> int:
        return max(self.get_max_money(root))
