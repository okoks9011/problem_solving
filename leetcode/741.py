import functools


class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        @functools.lru_cache(None)
        def cal_max_pick(s, i, j):
            if s == 0:
                if i == 0 and j == 0:
                    return grid[0][0]
                else:
                    return -1
            if i < 0 or (s - i) < 0 or j < 0 or (s - j) < 0:
                return -1
            if grid[i][s-i] == -1 or grid[j][s-j] == -1:
                return -1

            result = -1
            for d1 in [0, -1]:
                for d2 in [0, -1]:
                    result = max(result, cal_max_pick(s-1, i+d1, j+d2))
            if result == -1:
                return -1

            result += grid[i][s-i]
            if i != j:
                result += grid[j][s-j]
            return result

        n = len(grid)
        result = cal_max_pick(2*n - 2, n-1, n-1)
        return result if result != -1 else 0
