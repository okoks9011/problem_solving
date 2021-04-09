import re
import operator
from functools import lru_cache
from itertools import product


class Solution:
    def diffWaysToCompute(self, exp: str) -> List[int]:
        assert exp
        nums = tuple(int(v) for v in re.split('-|\+|\*', exp))
        if len(nums) <= 1:
            return nums

        ops = tuple(x for x in exp if not x.isdigit())
        assert len(nums) == len(ops) + 1

        op_dic = {
            '-': operator.sub,
            '+': operator.add,
            '*': operator.mul,
        }

        @lru_cache(None)
        def cal(ops, nums):
            if not ops:
                return nums
            cur_res = []
            for i, op in enumerate(ops):
                left_res = cal(ops[:i], nums[:i+1])
                right_res = cal(ops[i+1:], nums[i+1:])
                for l, r in product(left_res, right_res):
                    cur_res.append(op_dic[op](l, r))
            return cur_res

        return cal(ops, nums)
