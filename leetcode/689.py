class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        acc = [0] * (n + 1)
        for i in range(n):
            acc[i+1] = acc[i] + nums[i]

        dp1 = [0] * (n - k + 1)
        cur = float('-inf')
        for i in range(len(dp1) - 1, -1, -1):
            cur = max(cur, (acc[i+k] - acc[i]))
            dp1[i] = cur

        dp2 = [0] * (n - 2 * k + 1)
        cur = float('-inf')
        for i in range(len(dp2) - 1, -1, -1):
            cur = max(cur, (acc[i+k] - acc[i]) + dp1[i+k])
            dp2[i] = cur

        dp3 = [0] * (n - 3 * k + 1)
        cur = float('-inf')
        for i in range(len(dp3) - 1, -1, -1):
            cur = max(cur, (acc[i+k] - acc[i]) + dp2[i+k])
            dp3[i] = cur
        return cur  # wrong answer
