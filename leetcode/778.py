class Solution:
    def bfs(self, grid: List[List[int]], k) -> bool:
        n = len(grid)
        ds = [(-1, 0), (0, 1), (1, 0), (0, -1)]

        visited = [[False] * n for _ in range(n)]
        visited[0][0] = True
        cur_q = [(0, 0)]

        while cur_q:
            next_q = []
            for i, j in cur_q:
                for di, dj in ds:
                    ni, nj = i + di, j + dj
                    if (not (0 <= ni < n)) or (not (0 <= nj < n)):
                        continue
                    if grid[ni][nj] > k:
                        continue
                    if visited[ni][nj]:
                        continue
                    if ni == nj == (n - 1):
                        return True
                    visited[ni][nj] = True
                    next_q.append((ni, nj))
            cur_q = next_q
        return False

    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        left = grid[0][0]
        right = n * n - 1
        result = -1
        while left <= right:
            mid = left + (right - left) // 2
            if self.bfs(grid, mid):
                result = mid
                right = mid - 1
            else:
                left = mid + 1
        return result
