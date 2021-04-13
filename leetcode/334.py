class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        pre = []
        for i, ni in enumerate(nums):
            if any(x for x in nums[:i] if x < ni):
                pre.append(ni)
        if not pre:
            return False
        for i, pi in enumerate(pre):
            if any(x for x in pre[:i] if x < pi):
                return True
        return False
