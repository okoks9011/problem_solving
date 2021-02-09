# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        result = {}
        visited = set()
        def get_string(node):
            if node is None:
                return '()'

            left_str, right_str = get_string(node.left), get_string(node.right)
            cur_str = f'({left_str},{node.val},{right_str})'
            if cur_str in visited:
                if cur_str not in result:
                    result[cur_str] = node
            else:
                visited.add(cur_str)

            return cur_str

        get_string(root)
        return result.values()
