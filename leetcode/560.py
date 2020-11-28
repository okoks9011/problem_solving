from collections import defaultdict


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        cnt = defaultdict(int)
        cnt[0] = 1
        acc = 0
        result = 0
        for ni in nums:
            acc += ni
            result += cnt.get(acc - k, 0)
            cnt[acc] += 1
        return result
