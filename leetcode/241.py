import re


class Solution:
    def diffWaysToCompute(self, exp: str) -> List[int]:
        assert exp
        nums = [int(v) for v in re.split('-|\+|\*', exp)]
        if len(nums) <= 1:
            return nums

        ops = [x for x in exp if not x.isdigit()]
        assert len(nums) == len(ops) + 1

        op_dic = {
            '-': (lambda x, y: x - y),
            '+': (lambda x, y: x + y),
            '*': (lambda x, y: x * y),
        }
        def cal(ops, nums):
            if not ops:
                return nums
            cur_res = []
            for i, op in enumerate(ops):
                left_res = cal(ops[:i], nums[:i+1])
                right_res = cal(ops[i+1:], nums[i+1:])
                for l in left_res:
                    for r in right_res:
                        cur_res.append(op_dic[op](l, r))
            return cur_res

        return cal(ops, nums)
