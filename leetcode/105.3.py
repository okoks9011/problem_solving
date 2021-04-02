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

        loc = {v: i for i, v in enumerate(inorder)}
        self.pre_i = 0
        def build_tree_rec(left, right):
            if left > right:
                return None
            val = preorder[self.pre_i]
            self.pre_i += 1
            h_idx = loc[val]
            left_child = build_tree_rec(left, h_idx-1)
            right_child = build_tree_rec(h_idx+1, right)
            return TreeNode(val, left_child, right_child)

        return build_tree_rec(0, len(inorder)-1)
