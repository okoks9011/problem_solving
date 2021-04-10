import heapq
from collections import defaultdict


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        cnt = defaultdict(int)
        max_pq = []
        for ni in nums[:k-1]:
            heapq.heappush(max_pq, -ni)
            cnt[ni] += 1

        result = []
        for i in range(k-1, n):
            ni = nums[i]
            heapq.heappush(max_pq, -ni)
            cnt[ni] += 1

            result.append(-max_pq[0])

            nj = nums[i-k+1]
            cnt[nj] -= 1
            if cnt[nj] == 0:
                del cnt[nj]
            while max_pq and -max_pq[0] not in cnt:
                heapq.heappop(max_pq)
        return result
