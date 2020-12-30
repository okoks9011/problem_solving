import bisect

class Solution:
    def rank(self, matrix, target):
        result = 0
        for row in matrix:
            result += bisect.bisect_left(row, target)
        return result

    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        lo = matrix[0][0]
        hi = matrix[-1][-1]
        result = -1
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            if self.rank(matrix, mid) <= k-1:
                result = mid
                lo = mid + 1
            else:
                hi = mid - 1
        return result
