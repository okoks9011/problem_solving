# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def clone(self, tree):
        if not tree:
            return None
        return TreeNode(0, self.clone(tree.left), self.clone(tree.right))

    def combine(self, left_tree, right_tree):
        results = []
        for l in left_tree:
            for r in right_tree:
                results.append(TreeNode(0, self.clone(l), self.clone(r)))
        return results

    def allPossibleFBT(self, N: int) -> List[TreeNode]:
        dp = [[] for _ in range(N+1)]
        dp[1].append(TreeNode())
        for k in range(2, N+1):
            for i in range (1, k-1):
                dp[k].extend(self.combine(dp[i], dp[k-1-i]))
        return dp[N]
