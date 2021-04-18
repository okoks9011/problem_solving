class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        assert n
        m = len(grid[0])
        assert m

        def dfs(i, j):
            if i < 0 or n <= i or j < 0 or m <= j:
                return False
            if grid[i][j] != 0:
                return False
            grid[i][j] = 1

            dfs(i-1, j)
            dfs(i, j+1)
            dfs(i+1, j)
            dfs(i, j-1)
            return True

        for j in range(m):
            dfs(0, j)
            dfs(n-1, j)
        for i in range(n):
            dfs(i, 0)
            dfs(i, m-1)

        result = 0
        for i in range(1, n-1):
            for j in range(1, m-1):
                if dfs(i, j):
                    result += 1
        return result
