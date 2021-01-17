import sortedcontainers


class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        n = len(nums)
        sl = sortedcontainers.SortedList(nums[:k-1])
        result = []
        mid = k // 2

        for i in range(n - k + 1):
            sl.add(nums[i + k - 1])
            if k % 2 == 0:
                result.append((sl[mid-1] + sl[mid]) / 2)
            else:
                result.append(sl[mid])
            sl.remove(nums[i])
        return result
