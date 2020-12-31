import collections


class Solution:
    def shortestSubarray(self, A: List[int], K: int) -> int:
        que = collections.deque([(-1, 0)])
        result = float('inf')
        acc = 0
        for i, ai in enumerate(A):
            acc += ai
            while que and (acc - que[0][1]) >= K:
                result = min(result, i - que.popleft()[0])
            while que and que[-1][1] >= acc:
                que.pop()
            que.append((i, acc))

        if result < float('inf'):
            return result
        else:
            return -1
