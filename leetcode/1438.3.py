from collections import deque


class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        min_q, max_q = deque(), deque()
        result = 0
        tail = 0
        for i, ni in enumerate(nums):
            while min_q and min_q[-1] > ni:
                min_q.pop()
            while max_q and max_q[-1] < ni:
                max_q.pop()
            min_q.append(ni)
            max_q.append(ni)

            while min_q and max_q and max_q[0] - min_q[0] > limit:
                if min_q[0] == nums[tail]:
                    min_q.popleft()
                if max_q[0] == nums[tail]:
                    max_q.popleft()
                tail += 1
            result = max(result, i-tail+1)
        return result
