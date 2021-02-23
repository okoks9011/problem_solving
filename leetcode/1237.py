"""
   This is the custom function interface.
   You should not implement it, or speculate about its implementation
   class CustomFunction:
       # Returns f(x, y) for any given positive integers x and y.
       # Note that f(x, y) is increasing with respect to both x and y.
       # i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
       def f(self, x, y):

"""

class Solution:
    def findSolution(self, custom: 'CustomFunction', z: int) -> List[List[int]]:
        def find_y(x):
            left, right = 1, 1000
            while left <= right:
                mid =  left + (right - left) // 2
                v = custom.f(x, mid)
                if v == z:
                    return mid
                elif v < z:
                    left = mid + 1
                else:  # v > z:
                    right = mid - 1
            return -1

        result = []
        for x in range(1, 1001):
            if custom.f(x, 1) > z:
                break
            y = find_y(x)
            if y != -1:
                result.append([x, y])
        return result
