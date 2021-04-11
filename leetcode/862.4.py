import heapq


class Solution:
    def shortestSubarray(self, A: List[int], k: int) -> int:
        n = len(A)
        acc = 0
        result = n + 1
        min_pq = [(0, -1)]
        for i, ai in enumerate(A):
            acc += ai
            while min_pq and min_pq[0][0] <= acc - k:
                _, j = heapq.heappop(min_pq)
                result = min(result, i-j)
            heapq.heappush(min_pq, (acc, i))

        if result == n + 1:
            return -1
        return result
