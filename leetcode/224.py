import operator


class Solution:
    def calculate(self, s: str) -> int:
        op_dic = {'+': operator.add, '-': operator.sub}
        s = s.replace(' ', '')

        read_num = 0

        acc_stack = []
        op_stack = []
        acc = 0
        last_op = '+'

        for si in s:
            if si.isdigit():
                read_num *= 10
                read_num += int(si)
                continue

            if si == '(':
                acc_stack.append(acc)
                acc = 0
                op_stack.append(last_op)
                last_op = '+'
            elif si == '-' or si == '+':
                acc = op_dic[last_op](acc, read_num)
                last_op = si
            elif si == ')':
                cur_acc = op_dic[last_op](acc, read_num)
                saved_op = op_stack.pop()
                saved_acc = acc_stack.pop()
                acc = op_dic[saved_op](saved_acc, cur_acc)
            else:
                assert f'Unknown character {si}'
            read_num = 0
        return op_dic[last_op](acc, read_num)
