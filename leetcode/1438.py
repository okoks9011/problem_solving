import heapq
from collections import Counter


class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        cnt = Counter()
        min_pq, max_pq = [], []
        result = 0
        tail = 0
        for i, ai in enumerate(nums):
            cnt[ai] += 1
            heapq.heappush(min_pq, ai)
            heapq.heappush(max_pq, -ai)

            while min_pq and max_pq and (-max_pq[0])-min_pq[0] > limit:
                ti = nums[tail]
                cnt[ti] -= 1
                if cnt[ti] == 0:
                    del cnt[ti]
                while min_pq and min_pq[0] not in cnt:
                    heapq.heappop(min_pq)
                while max_pq and -max_pq[0] not in cnt:
                    heapq.heappop(max_pq)
                tail += 1
            result = max(result, i-tail+1)

        return result
