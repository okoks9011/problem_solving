class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        r = len(grid)
        assert r > 0
        c = len(grid[0])
        assert c > 0

        ds = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        def dfs(i, j):
            if i < 0 or r <= i or j < 0 or c <= j:
                return False
            if grid[i][j] != '1':
                return False
            grid[i][j] = '0'

            for di, dj in ds:
                ni, nj = i + di, j + dj
                dfs(ni, nj)
            return True

        result = 0
        for i in range(r):
            for j in range(c):
                if dfs(i, j):
                    result += 1
        return result
