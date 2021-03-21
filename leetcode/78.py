class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return [[]]
        head, tail_result = nums[0], self.subsets(nums[1:])
        new_result = list(tail_result)
        for r in tail_result:
            new_result.append([head] + r)
        return new_result
