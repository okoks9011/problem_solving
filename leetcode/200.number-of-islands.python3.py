class Solution:
    def traverse(self, grid, i, j, n, m):
        grid[i][j] = '0'

        adjs = [
            (i-1, j),
            (i+1, j),
            (i, j-1),
            (i, j+1)
        ]
        for adj_i, adj_j in adjs:
            if 0 <= adj_i < n and 0 <= adj_j < m and grid[adj_i][adj_j] == '1':
                self.traverse(grid, adj_i, adj_j, n, m)

    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
            return 0

        n = len(grid)
        if n == 0:
            return 0

        m = len(grid[0])

        count = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1':
                    count += 1
                    self.traverse(grid, i, j, n, m)

        return count
