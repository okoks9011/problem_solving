class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        dp = list(nums)

        for i in range(1, n):
            if dp[i-1] > 0:
                dp[i] += dp[i-1]
        return max(dp)
