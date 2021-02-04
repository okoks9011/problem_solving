class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        left, right = [], []
        middle = newInterval
        for inter in intervals:
            if inter[1] < middle[0]:
                left.append(inter)
            elif inter[0] > middle[1]:
                right.append(inter)
            else:
                middle[0] = min(middle[0], inter[0])
                middle[1] = max(middle[1], inter[1])
        return left + [middle] + right
