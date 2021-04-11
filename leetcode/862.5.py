from collections import deque


class Solution:
    def shortestSubarray(self, A: List[int], k: int) -> int:
        n = len(A)
        # acc = itertools.accumulate(A, initial=0)
        acc = [0] * (n + 1)
        for i in range(n):
            acc[i+1] = acc[i] + A[i]

        que = deque()
        result = n + 1
        for i, acc_i in enumerate(acc):
            while que and acc_i - acc[que[0]] >= k:
                j = que.popleft()
                result = min(result, i - j)
            while que and acc[que[-1]] >= acc_i:
                que.pop()
            que.append(i)

        if result == n + 1:
            return -1
        return result
