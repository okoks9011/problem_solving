import heapq
from collections import defaultdict


class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.ts = 0
        self.min_pq = []
        self.data = {}
        self.cnt = defaultdict(int)

    def touch(self, key: int) -> None:
        self.cnt[key] += 1
        heapq.heappush(self.min_pq, (self.cnt[key], self.ts, key))
        self.ts += 1

    def get(self, key: int) -> int:
        if key in self.data:
            self.touch(key)
            return self.data[key]
        return -1

    def evict(self):
        while True:
            assert self.min_pq
            key_cnt, _, key = self.min_pq[0]
            if self.cnt[key] == key_cnt:
                break
            heapq.heappop(self.min_pq)

        _, _, key = heapq.heappop(self.min_pq)
        del self.data[key]
        del self.cnt[key]

    def put(self, key: int, value: int) -> None:
        if self.capacity <= 0:
            return

        if key in self.data:
            self.touch(key)
            self.data[key] = value
            return

        if len(self.data) >= self.capacity:
            self.evict()
        self.touch(key)
        self.data[key] = value


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
