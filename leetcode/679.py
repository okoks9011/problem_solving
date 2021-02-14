import math


class Solution:
    def judgePoint24(self, nums: List[int]) -> bool:
        def gen_perm(t):
            if not t:
                return []
            if len(t) == 1:
                return [t]

            result = []
            for i in range(len(t)):
                result += [ri.copy() + [t[i]] for ri in gen_perm(t[:i] + t[i+1:])]
            return result

        ops = [
            (lambda p: p[0] + p[1]),
            (lambda p: p[0] - p[1]),
            (lambda p: p[1] - p[0]),
            (lambda p: p[0] * p[1]),
            (lambda p: p[0] / p[1]),
            (lambda p: p[1] / p[0]),
        ]

        perms = gen_perm(nums)
        for p1, p2, p3, p4 in perms:
            for op1 in ops:
                for op2 in ops:
                    for op3 in ops:
                        try:
                            v1 = op1((op2((p1, p2)), op3((p3, p4))))
                            if math.isclose(v1, 24):
                                print(p1, p2, p3, p4)
                                return True
                            v2 = op1((op2((op3((p1, p2)), p3)), p4))
                            if math.isclose(v2, 24):
                                print(p1, p2, p3, p4)
                                return True
                        except:
                            pass
        return False
