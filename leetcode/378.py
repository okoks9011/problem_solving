class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        result = []
        for row in matrix:
            result.extend(row)
        result.sort()
        return result[k]
