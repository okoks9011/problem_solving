class Solution:
    def numSubmat(self, grid: List[List[int]]) -> int:
        n = len(grid)
        assert n > 0
        m = len(grid[0])
        assert m > 0

        for row in grid:
            for j in range(1, m):
                if row[j] != 0:
                    row[j] += row[j-1]

        result = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 0:
                    continue

                limit = grid[i][j]
                for k in range(i-1, -1, -1):
                    if grid[k][j] == 0:
                        break
                    limit = min(grid[k][j], limit)
                    result += limit

        return result
