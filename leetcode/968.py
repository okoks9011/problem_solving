# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from enum import Enum


class Status(Enum):
    covered = 1
    free = 2
    must = 3


class Solution:
    def minCameraCover(self, root: TreeNode) -> int:
        dp = {}

        def cal_min_camera(node, status):
            if node is None:
                return 0

            key = id(node), status
            if key in dp:
                return dp[key]

            result = float('inf')
            if status == Status.covered:
                choose = 1 + cal_min_camera(node.left, Status.covered) + \
                    cal_min_camera(node.right, Status.covered)
                not_choose = cal_min_camera(node.left, Status.free) + \
                    cal_min_camera(node.right, Status.free)
                result = min(result, choose, not_choose)
            elif status == Status.free:
                choose = 1 + cal_min_camera(node.left, Status.covered) + \
                    cal_min_camera(node.right, Status.covered)
                not_choose = float('inf')
                if node.left:
                    not_choose = min(
                        not_choose,
                        cal_min_camera(node.left, Status.must) + cal_min_camera(node.right, Status.free)
                    )
                if node.right:
                    not_choose = min(
                        not_choose,
                        cal_min_camera(node.left, Status.free) + cal_min_camera(node.right, Status.must)
                    )
                result = min(result, choose, not_choose)
            elif status == Status.must:
                result = 1 + cal_min_camera(node.left, Status.covered) + \
                    cal_min_camera(node.right, Status.covered)
            else:
                assert False

            dp[key] = result
            return result

        return cal_min_camera(root, Status.free)
