class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        t = len(nums) - 2
        while t >= 0 and nums[t] >= nums[t+1]:
            t -= 1

        # if everything is increasing order, it is maximum value
        if t == -1:
            nums.reverse()
            return

        for i in range(len(nums) - 1, t, -1):
            if nums[i] > nums[t]:
                nums[i], nums[t] = nums[t], nums[i]
                break

        nums[t+1:] = reversed(nums[t+1:])
