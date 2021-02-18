import heapq


class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.min_pq = []
        self.max_pq = []

    def addNum(self, num: int) -> None:
        min_pq, max_pq = self.min_pq, self.max_pq
        heapq.heappush(min_pq, num)

        if (len(min_pq) + len(max_pq)) % 2 == 0:
            v = heapq.heappop(min_pq)
            heapq.heappush(max_pq, -v)
        else:
            if max_pq and min_pq[0] < -max_pq[0]:
                small = heapq.heappop(min_pq)
                big = -heapq.heappop(max_pq)
                heapq.heappush(min_pq, big)
                heapq.heappush(max_pq, -small)

    def findMedian(self) -> float:
        min_pq, max_pq = self.min_pq, self.max_pq
        if (len(min_pq) + len(max_pq)) % 2 == 0:
            return (min_pq[0] - max_pq[0]) / 2
        else:
            return min_pq[0]

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
