class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        assert n >= 0
        m = len(grid)
        assert m >= 0

        ds = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        def dfs(i, j):
            if i < 0 or n <= i or j < 0 or m <= j:
                return 0
            if grid[i][j] == 0:
                return 0
            grid[i][j] = 0
            result = 1
            for di, dj in ds:
                ci, cj = i + di, j + dj
                result += dfs(ci, cj)
            return result

        max_size = 0
        for i in range(n):
            for j in range(m):
                max_size = max(max_size, dfs(i, j))
        return max_size
