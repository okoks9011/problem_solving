class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) <= 1:
            return intervals

        intervals.sort()
        result = []
        t_s, t_e = intervals[0]
        for cur_s, cur_e in intervals[1:]:
            if t_e < cur_s:
                result.append((t_s, t_e))
                t_s, t_e = cur_s, cur_e
                continue
            t_e = max(t_e, cur_e)
        result.append((t_s, t_e))

        return result
