class Solution:
    def two_sum(self, nums: List[int], k) -> List[List[int]]:
        result = set()
        left, right = 0, len(nums)-1
        while left < right:
            cur = nums[left] + nums[right]
            if cur == k:
                result.add((nums[left], nums[right]))
                right -= 1
                left += 1
            elif cur > k:
                right -= 1
            else:  # cur < k
                left += 1
        return result

    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        result = set()
        for i in range(n):
            two_result = self.two_sum(nums[:i], -nums[i])
            for two in two_result:
                result.add((two[0], two[1], nums[i]))
        return list(result)
