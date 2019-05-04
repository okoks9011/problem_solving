from collections import defaultdict

class Solution:
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        t = defaultdict(int)
        t[0] = 1
        for n in nums:
            u = defaultdict(int)
            for k, tk in t.items():
                u[k + n] += tk
                u[k - n] += tk
            t = u
        return u[S]
