class Solution:
    def is_possible(self, acc, K, target):
        end = target
        while end < len(acc):
            start = end - target
            if (acc[end] - acc[start]) >= K:
                return True
            end += 1
        return False

    def shortestSubarray(self, A: List[int], K: int) -> int:
        n = len(A)
        acc = [0] * (n + 1)
        for i in range(1, n + 1):
            acc[i] = acc[i-1] + A[i-1]

        left = 1
        right = n
        result = -1
        while left <= right:
            mid = left + (right - left) // 2
            if self.is_possible(acc, K, mid):
                result = mid
                right = mid - 1
            else:
                left = mid + 1
        return result
