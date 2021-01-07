"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def copy_node(self, ori):
        if ori.val in self.d:
            return self.d[ori.val]
        result = Node(ori.val)
        self.d[ori.val] = result
        for ori_nei in ori.neighbors:
            result.neighbors.append(self.copy_node(ori_nei))
        return result

    def cloneGraph(self, node: 'Node') -> 'Node':
        self.d = {}
        if not node:
            return None
        return self.copy_node(node)
