# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if root is None:
            return 0

        left, left_len = root.left, 0
        while left:
            left = left.left
            left_len += 1

        right, right_len = root.right, 0
        while right:
            right = right.right
            right_len += 1

        if left_len == right_len:
            return 2 ** (1 + left_len) - 1
        else:
            return 1 + self.countNodes(root.left) + self.countNodes(root.right)
