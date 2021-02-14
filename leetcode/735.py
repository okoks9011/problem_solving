class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        result = []
        for a in asteroids:
            if a > 0:
                result.append(a)
                continue
            assert a != 0
            put = True
            while put and result and result[-1] > 0:
                if result[-1] >= abs(a):
                    put = False
                if result[-1] <= abs(a):
                    result.pop()
            if put:
                result.append(a)

        return result
