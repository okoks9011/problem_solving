import collections
import heapq


class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        adjs = collections.defaultdict(set)
        for u, v, w in times:
            adjs[u-1].add((v-1, w))

        dist = [float('inf') for _ in range(N)]
        dist[K-1] = 0
        min_pq = []
        heapq.heappush(min_pq, (0, K-1))

        while min_pq:
            cost, here = heapq.heappop(min_pq)
            if cost > dist[here]:
                continue
            for there, weight  in adjs[here]:
                next_cost = cost + weight
                if dist[there] > next_cost:
                    dist[there] = next_cost
                    heapq.heappush(min_pq, (next_cost, there))

        result = max(dist)
        if result == float('inf'):
            return -1
        else:
            return result
