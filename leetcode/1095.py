# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def find_top(self, m: 'MountainArray') -> int:
        n = m.length()
        left, right = 1, (n - 2)
        while left <= right:
            mid = left + (right - left) // 2
            pr, cur, ne = m.get(mid-1), m.get(mid), m.get(mid+1)
            if pr < cur < ne:
                left = mid + 1
            elif pr > cur > ne:
                right = mid - 1
            else:
                return mid
        assert False

    def find_value(self, compare, start: int, end: int, m: 'MountainArray') -> int:
        left, right = start, end
        while left <= right:
            mid = left + (right - left) // 2
            v = m.get(mid)
            if compare(v) < 0:
                left = mid + 1
            elif compare(v) > 0:
                right = mid - 1
            else:  # v == target
                return mid
        return -1

    def findInMountainArray(self, target: int, m: 'MountainArray') -> int:
        top = self.find_top(m)

        left_result = self.find_value((lambda v: v - target), 0, top, m)
        if left_result != -1:
            return left_result

        right_result = self.find_value((lambda v: target - v), top, m.length(), m)
        return right_result
