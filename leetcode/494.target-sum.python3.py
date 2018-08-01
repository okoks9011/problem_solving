class Solution:
    def __init__(self):
        self.nums = None
        self.d = {}

    def numSum(self, i, s):
        if not (i, s) in self.d:
            result = 0
            if i < 0:
                if s == 0:
                    result = 1
            else:
                result += self.numSum(i-1, s+self.nums[i])
                result += self.numSum(i-1, s-self.nums[i])
            self.d[(i, s)] = result
        return self.d[(i, s)]

    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        self.nums = nums
        return self.numSum(len(nums)-1, S)
