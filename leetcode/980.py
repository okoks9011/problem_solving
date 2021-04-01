class Solution:
    def __init__(self):
        self.result = 0

    def find_value(self, v, grid):
        for i, row in enumerate(grid):
            for j, c in enumerate(row):
                if c == v:
                    return i, j
        assert False

    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        n = len(grid)
        assert n > 0
        m = len(grid[0])
        assert m > 0

        si, sj = self.find_value(1, grid)
        walks = 1
        for row in grid:
            walks += sum(1 for c in row if c == 0)

        ds = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        def dfs(i, j, w):
            if i < 0 or n <= i or j < 0 or m <= j:
                return
            if grid[i][j] == 2 and w == walks:
                self.result += 1
                return
            if grid[i][j] < 0:
                return

            ori = grid[i][j]
            grid[i][j] = -1
            for di, dj in ds:
                dfs(i+di, j+dj, w+1)
            grid[i][j] = ori

        dfs(si, sj, 0)
        return self.result
