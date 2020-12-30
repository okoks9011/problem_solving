class Solution:
    def maxAbsValExpr(self, arr1: List[int], arr2: List[int]) -> int:
        n = len(arr1)
        comb = [[] for _ in range(4)]
        for i, ai, bi in zip(range(n), arr1, arr2):
            comb[0].append(ai + bi + i)
            comb[1].append(ai - bi + i)
            comb[2].append(ai + bi - i)
            comb[3].append(ai - bi - i)

        result = 0
        for candi in comb:
            result = max(result, abs(max(candi) - min(candi)))
        return result
