import enum
import functools


class Flow(enum.Enum):
    P = 1
    A = 2
    B = 3
    N = 4


class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        n = len(matrix)
        assert n > 0
        m = len(matrix[0])
        assert m > 0

        ds = [
            (-1, 0), (0, 1), (1, 0), (0, -1),
        ]
        functools.lru_cache(None)
        def get_flow(i, j):
            print(i, j)
            if i < 0 or j < 0:
                return Flow.P
            elif i >= n or j >= m:
                return Flow.A

            cur_v = matrix[i][j]
            flows = []
            for di, dj in ds:
                ni, nj = (i + di), (j + dj)
                if cur_v < matrix[ni][nj]:
                    continue
                flows.append(get_flow(ni, nj))
            if not flows:
                return Flow.N
            if all(map(lambda x: x == Flow.P or x == Flow.N, flows)):
                return Flow.P
            elif all(map(lambda x: x == Flow.A or x == Flow.N, flows)):
                return Flow.A
            else:
                return Flow.B

        result = []
        for i in range(n):
            for j in range(m):
                if get_flow(i, j) == Flow.B:
                    result.append([i, j])
        return result
