class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(len(nums)):
            while 1 <= nums[i] <= n and nums[i] != i + 1:
                v = nums[i] - 1
                if nums[v] == v + 1:
                    break
                nums[i], nums[v] = nums[v], nums[i]
        for i, v in enumerate(nums):
            if i + 1 != v:
                return i + 1
        return n + 1
