class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        loc = {0: -1}
        acc, result = 0, 0
        for i, ni in enumerate(nums):
            acc += 1 if ni == 1 else -1

            if acc in loc:
                result = max(result, i - loc[acc])
            else:
                loc[acc] = i
        return result
