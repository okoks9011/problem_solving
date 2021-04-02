# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder or not inorder:
            return None

        h = preorder[0]
        h_idx = inorder.index(h)

        left = self.buildTree(preorder[1:h+1], inorder[:h])
        right = self.buildTree(preorder[h+1:], inorder[h+1:])
        return TreeNode(h, left, right)
