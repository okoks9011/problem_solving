class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        t = 0
        for i in range(len(nums) - 1, 0, -1):
            if nums[i-1] < nums[i]:
                t = i
                break

        # if everything is increasing order, it is maximum value
        if t == 0:
            nums.reverse()
            return

        min_i = t
        for i in range(t, len(nums)):
            if nums[i] > nums[t-1] and nums[i] <= nums[min_i]:
                min_i = i
        nums[min_i], nums[t-1] = nums[t-1], nums[min_i]

        nums[t:] = reversed(nums[t:])
