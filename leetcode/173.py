# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


def flatten(node):
    if node is None:
        return []
    return flatten(node.left) + [node.val] + flatten(node.right)


class BSTIterator:

    def __init__(self, root: TreeNode):
        self.buf = flatten(root)
        self.i = 0

    def next(self) -> int:
        result = self.buf[self.i]
        self.i += 1
        return result

    def hasNext(self) -> bool:
        return self.i < len(self.buf)


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
