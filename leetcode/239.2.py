from sortedcontainers import SortedList


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        sl = SortedList()
        for ni in nums[:k-1]:
            sl.add(ni)

        result = []
        for i in range(k-1, n):
            sl.add(nums[i])
            result.append(sl[-1])
            sl.remove(nums[i-k+1])

        return result
