class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        tail = 0
        acc = 0
        result = float('inf')
        for head, v in enumerate(nums):
            acc += v
            while tail <= head and acc >= s:
                result = min(result, head - tail + 1)
                acc -= nums[tail]
                tail += 1

        if result < float('inf'):
            return result
        else:
            return 0
