import collections


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        c = collections.Counter(nums)
        # return [x for x, _ in c.most_common(k)]

        return [x for x, _ in sorted(c.items(), key=lambda x: x[1], reverse=True)[:k]]
