import bisect


class TimeMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.buf = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        ts, vs = self.buf.get(key, ([], []))
        ts.append(timestamp)
        vs.append(value)
        self.buf[key] = ts, vs

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.buf:
            return ''

        ts, vs = self.buf[key]
        i = bisect.bisect_right(ts, timestamp)
        if i == 0:
            return ''
        return vs[i-1]


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
