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
        def build_tree_rec(pre_left, pre_right, in_left, in_right):
            if pre_left > pre_right or in_left > in_right:
                return None
            h = preorder[pre_left]
            h_idx = loc[h]
            left_size = h_idx - in_left
            left_child = build_tree_rec(pre_left+1, pre_left+left_size, in_ieft, h_idx-1)
            right_size = in_right - h_idx
            right_child = build_tree_rec(pre_right-right_size+1, pre_right, h_idx+1, in_right)
            return TreeNode(h, left_child, right_child)

        n = len(preorder)
        return build_tree_rec(0, n-1, 0, n-1)
