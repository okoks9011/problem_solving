import bisect


class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        assert n > 0
        m = len(matrix[0])
        assert m > 0

        row_accs = []
        for row in matrix:
            cur = [0]
            for c in row:
                cur.append(c + cur[-1])
            row_accs.append(cur)

        result = float('-inf')
        for l in range(m+1):
            for r in range(l+1, m+1):
                row_sums = [row_accs[i][r] - row_accs[i][l] for i in range(n)]

                row_sum_accs = [0]
                acc = 0
                for v in row_sums:
                    acc += v
                    t = bisect.bisect_left(row_sum_accs, acc - k)
                    if t < len(row_sum_accs):
                        result = max(result, acc - row_sum_accs[t])
                    bisect.insort(row_sum_accs, acc)
        return result
