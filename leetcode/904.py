import collections


class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        c = collections.Counter()
        tail = 0
        result = 0
        for i, ti in enumerate(tree):
            c[ti] += 1
            while len(c) > 2 and tail <= i:
                tj = tree[tail]
                c[tj] -= 1
                if c[tj] == 0:
                    del c[tj]
                tail += 1
            result = max(result, i - tail + 1)
        return result
