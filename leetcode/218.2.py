import heapq


class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        max_pq = []
        rightmost = 0
        result = []
        for left, right, height in sorted(buildings):
            heapq.heappush(max_pq, (-height, right))
            rigtmost = max(rightmost, right)

            while max_pq:
                top = max_pq[0]
                max_height, effect_end = -top[0], top[1]
                if left < effect_end:
                    break
                heapq.heappop(max_pq)
            if not result or result[-1][1] != max_height:
                result.append([left, max_height])
        result.append([rightmost, 0])

        return result
