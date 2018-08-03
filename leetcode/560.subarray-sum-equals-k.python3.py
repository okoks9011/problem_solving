class Solution:
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        counts = 0
        for s in range(len(nums)):
            acc = 0
            for i in range(s, len(nums)):
                acc += nums[i]
                if acc == k:
                    counts += 1

        return counts
