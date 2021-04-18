from collections import defaultdict


class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        dic = defaultdict(int)
        for t in time:
            dic[t % 60] += 1

        result = 0
        for i in range(1, 30):
            result += dic[i] * dic[60-i]

        result += dic[0] * (dic[0]-1) // 2
        result += dic[30] * (dic[30]-1) // 2
        return result
