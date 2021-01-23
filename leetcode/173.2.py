# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class BSTIterator:

    def __init__(self, root: TreeNode):
        self.stack = []
        self.cur = root
        self.has_next = root is not None

    def next(self) -> int:
        while self.cur.left is not None:
            self.stack.append(self.cur)
            prev = self.cur
            self.cur = self.cur.left
            prev.left = None

        result = self.cur.val

        if self.cur.right is not None:
            self.cur = self.cur.right
        elif self.stack:
            self.cur = self.stack.pop()
        else:
            self.has_next = False
        return result

    def hasNext(self) -> bool:
        return self.has_next


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
