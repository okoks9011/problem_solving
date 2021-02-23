class Solution:
    def rob(self, nums: List[int]) -> int:
        cur, prev, pprev = 0, 0, 0
        for ni in nums:
            cur = max(ni + pprev, prev)
            prev, pprev = cur, prev
        return cur

