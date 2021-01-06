import functools


class Solution:
    @functools.lru_cache
    def cal_min_sub(self, i: int, k: int) -> int:
        if k == 0:
            if i == self.n:
                return 0
            else:
                return -1
        if self.n - i < k:
            return -1
        cur_sum = 0
        result = float('inf')
        for j in range(i + 1, self.n - k + 2):
            cur_sum += self.nums[j-1]
            rest_min_sum = self.cal_min_sub(j, k - 1)
            if rest_min_sum == -1:
                continue
            largest = max(cur_sum, rest_min_sum)
            result = min(result, largest)
        return result

    def splitArray(self, nums: List[int], m: int) -> int:
        self.nums = nums
        self.n = len(nums)
        return self.cal_min_sub(0, m)
