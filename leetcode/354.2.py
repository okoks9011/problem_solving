import bisect


class Solution:
    def maxEnvelopes(self, envs: List[List[int]]) -> int:
        envs.sort(key=(lambda x: (x[0], -x[1])))
        heights = [h for _, h in envs]
        tails = []
        for h in heights:
            idx = bisect.bisect_left(tails, h)
            if len(tails) == idx:
                tails.append(h)
                continue
            tails[idx] = h
        return len(tails)
