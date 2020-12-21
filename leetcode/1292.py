class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        n = len(mat)
        assert n > 0
        m = len(mat[0])
        assert m > 0

        acc = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            row_sum = 0
            for j in range(1, m + 1):
                row_sum += mat[i-1][j-1]
                acc[i][j] = acc[i-1][j] + row_sum

        result = 0
        for si in range(n):
            for sj in range(m):
                k = 1
                while True:
                    ei = si + k
                    ej = sj + k
                    if ei > n or ej > m:
                        break
                    area = acc[ei][ej] - acc[ei][sj] - acc[si][ej] + acc[si][sj]
                    if area > threshold:
                        break
                    result = max(result, k)
                    k += 1
        return result
