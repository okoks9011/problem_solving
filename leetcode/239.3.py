from collections import deque


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        que = deque()
        result = []
        for i in range(n):
            while que and que[0] <= i - k:
                que.popleft()
            while que and nums[que[-1]] < nums[i]:
                que.pop()
            que.append(i)
            if i >= k - 1:
                result.append(nums[que[0]])
        return result
