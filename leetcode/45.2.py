class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 0

        cur_pos, max_pos, jumps = 0, 0, 1
        for i in range(n):
            if i > cur_pos:
                cur_pos = max_pos
                jumps += 1
            max_pos = max(max_pos, nums[i]+i)

        return jumps
