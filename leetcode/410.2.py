class Solution:
    def can_max_be(self, mid: int, nums: List[int], m: int) -> bool:
        acc = 0
        cnt = 1
        for ni in nums:
            if acc + ni <= mid:
                acc += ni
            else:
                acc = ni
                cnt += 1
            if cnt > m:
                return False
        return True

    def splitArray(self, nums: List[int], m: int) -> int:
        left = max(nums)
        right = sum(nums)
        result = -1

        while left <= right:
            mid = (right + left) // 2
            if self.can_max_be(mid, nums, m):
                result = mid
                right = mid - 1
            else:
                left = mid + 1
        return result
