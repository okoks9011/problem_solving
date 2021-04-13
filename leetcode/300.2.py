import bisect


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        tails = []
        for ni in nums:
            idx = bisect.bisect_left(tails, ni)
            if idx == len(tails):
                tails.append(ni)
                continue
            tails[idx] = ni
        return len(tails)
