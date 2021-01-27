import bisect


class RangeModule:

    def __init__(self):
        self.starts = []
        self.ends = []

    def addRange(self, left: int, right: int) -> None:
        left_idx = bisect.bisect_right(self.starts, left)
        if left_idx > 0 and left <= self.ends[left_idx-1]:
            header_idx = left_idx - 1
            cur_start = self.starts[left_idx-1]
        else:
            header_idx = left_idx
            cur_start = left

        right_idx = bisect.bisect_right(self.starts, right)
        footer_idx = right_idx
        if right_idx > 0:
            cur_ends =  max(self.ends[right_idx-1], right)
        else:
            cur_ends = right

        self.starts = self.starts[:header_idx] + [cur_start] + self.starts[footer_idx:]
        self.ends = self.ends[:header_idx] + [cur_ends] + self.ends[footer_idx:]

    def queryRange(self, left: int, right: int) -> bool:
        left_idx = bisect.bisect_right(self.starts, left)
        if left_idx == 0:
            return False

        return right <= self.ends[left_idx-1]

    def removeRange(self, left: int, right: int) -> None:
        starts_middle = []
        ends_middle = []
        left_idx = bisect.bisect_right(self.starts, left)
        if left_idx > 0 and left < self.ends[left_idx-1]:
            header_idx = left_idx - 1
            starts_middle.append(self.starts[left_idx-1])
            ends_middle.append(left)
        else:
            header_idx = left_idx

        right_idx = bisect.bisect_right(self.starts, right)
        footer_idx = right_idx
        if right_idx > 0 and right < self.ends[right_idx-1]:
            starts_middle.append(right)
            ends_middle.append(self.ends[right_idx-1])

        self.starts = self.starts[:header_idx] + starts_middle + self.starts[footer_idx:]
        self.ends = self.ends[:header_idx] + ends_middle + self.ends[footer_idx:]


# Your RangeModule object will be instantiated and called as such:
# obj = RangeModule()
# obj.addRange(left,right)
# param_2 = obj.queryRange(left,right)
# obj.removeRange(left,right)
