import random


class Solution:

    def __init__(self, nums: List[int]):
        self.buf = nums

    def reset(self) -> List[int]:
        """
        Resets the array to its original configuration and return it.
        """
        return self.buf

    def shuffle(self) -> List[int]:
        """
        Returns a random shuffling of the array.
        """
        nums = self.buf.copy()
        for i in range(1, len(nums)):
            t = random.randint(1, i)
            nums[i], nums[t] = nums[t], nums[i]

        return nums


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
