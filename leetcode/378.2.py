import heapq

class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        min_q = [(v, 0, i) for i, v in enumerate(matrix[0])]
        heapq.heapify(min_q)
        for _ in range(k - 1):
            v, r, c = heapq.heappop(min_q)
            r += 1
            if r < n:
                heapq.heappush(min_q, (matrix[r][c], r, c))
        return min_q[0][0]
