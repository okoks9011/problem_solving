class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        max_pos = 0
        for i, a in enumerate(nums):
            if i > max_pos:
                return False

            max_pos = max(max_pos, i + a)
            if max_pos >= len(nums) - 1:
                return True

        # not reachable
        return True
