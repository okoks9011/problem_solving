class Solution:
    def hitBricks(self, grid: List[List[int]], hits: List[List[int]]) -> List[int]:
        n = len(grid)
        m = len(grid[0])
        ds = [
            (-1, 0), (0, 1), (1, 0), (0, -1),
        ]

        def dfs(ci, cj, color):
            if ci < 0 or n <= ci or cj < 0 or m <= cj:
                return
            if grid[ci][cj] == 0:
                return
            if grid[ci][cj] == color:
                return
            grid[ci][cj] = color
            for d in ds:
                dfs(ci + d[0], cj + d[1], color)

        def check(color):
            result = 0
            for ci in range(n):
                for cj in range(m):
                    if grid[ci][cj] == 0 or grid[ci][cj] == color:
                        continue
                    grid[ci][cj] = 0
                    result += 1
            return result

        c = 2
        for cj in range(m):
            dfs(0, cj, c)
        check(c)
        c += 1

        results = []
        for hi, hj in hits:
            grid[hi][hj] = 0
            for cj in range(m):
                dfs(0, cj, c)
            results.append(check(c))
            c += 1
        return results
