# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        def cal_path_info(node):
            if node is None:
                return float('-inf'), 0
            left_max_path, left_max_down = cal_path_info(node.left)
            right_max_path, right_max_down = cal_path_info(node.right)

            cur_max_path = node.val
            if left_max_down > 0:
                cur_max_path += left_max_down
            if right_max_down > 0:
                cur_max_path += right_max_down

            cur_max_path = max(
                cur_max_path,
                left_max_path,
                right_max_path,
            )

            cur_max_down = max(
                0,
                node.val,
                node.val + max(left_max_down, right_max_down),
            )
            return cur_max_path, cur_max_down

        return cal_path_info(root)[0]
