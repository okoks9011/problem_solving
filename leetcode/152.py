import enum


class Direction(enum.Enum):
    INIT = 1
    UP = 2
    DOWN = 3


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        assert n >= 1
        cur = nums[0]
        result = cur
        stat = Direction.INIT
        start_i = 0
        for i in range(1, n):
            if cur != 0 and nums[i] != 0:
                if nums[i-1] + 1 == nums[i] and stat != Direction.DOWN:
                    cur *= nums[i]
                    result = max(result, cur)
                    stat = Direction.UP
                elif nums[i-1] - 1 == nums[i] and stat != Direction.UP:
                    cur *= nums[i]
                    result = max(result, cur)
                    result = max(result, cur // nums[start_i])
                    stat = Direction.DOWN
                else:
                    cur = nums[i]
                    result = max(result, cur)
                    stat = Direction.INIT
                    start_i = i
            else:
                cur = nums[i]
                result = max(result, cur)
                stat = Direction.INIT
                start_i = i
        return result
