class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [float('inf')] * n
        dp[0] = 0
        for i in range(n-1):
            for j in range(1, nums[i]+1):
                if i + j >= n:
                    continue
                dp[i+j] = min(dp[i+j], dp[i]+1)
        return dp[n-1]
