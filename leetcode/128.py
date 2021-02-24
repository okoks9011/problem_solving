class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        ns = set(nums)
        result = 0
        while ns:
            x = ns.pop()
            cur = 1

            right = x + 1
            while right in ns:
                ns.remove(right)
                right += 1
                cur += 1

            left = x - 1
            while left in ns:
                ns.remove(left)
                left -= 1
                cur += 1
            result = max(result, cur)
        return result
