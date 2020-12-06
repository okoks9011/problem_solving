class Solution:
    def longestSubsequence(self, arr: List[int], diff: int) -> int:
        max_length = {}
        for ai in arr:
            prev_length = max_length.get(ai - diff, 0)
            max_length[ai] = prev_length + 1
        return max(max_length.values())
