#!/usr/bin/python3

import sys


class FlipReverseArray(object):
    def __init__(self, n):
        self.left = []
        self.right = []
        self.last_same = -1
        self.last_diff = -1
        self.n = n
        self.reset()

    def reset(self):
        self.remain = 10

    def flip(self):
        self.right = [1 ^ i for i in self.right]
        self.left = [1 ^ i for i in self.left]

    def reverse(self):
        self.right, self.left = self.left, self.right

    def size(self):
        return len(self.left) + len(self.right)

    def value(self):
        return list(reversed(self.left)) + self.right

    def __repr__(self):
        return str(list(reversed(self.left))).rjust(30) + ' || ' + str(self.right)

    def orient(self):
        self.reset()
        if self.last_same != -1 and self.last_diff != -1:
            s_get, d_get = self.right_query(self.last_same), self.right_query(self.last_diff)
            s_cur, d_cur = self.right[self.last_same], self.right[self.last_diff]

            if s_get ^ d_get != s_cur ^ d_cur:
                self.reverse()
            if s_get != s_cur:
                self.flip()
        elif self.last_same != -1 or self.last_diff != -1:
            t = self.last_same if self.last_same != -1 else self.last_diff
            t_get = self.right_query(t)
            self.ask(1)  # padding

            t_cur = self.right[t]
            if t_get != t_cur:
                self.flip()
        else:
            assert False, 'At least one of index should be none -1'
            exit(1)

    def convert_idx(self, inner):
        half = self.n // 2
        return half - inner, half + inner + 1

    def ask(self, outer):
        print(outer)
        sys.stdout.flush()

        r = input()
        if r not in ('0', '1'):
            assert False, 'Incorrect return: {}'.format(r)
            exit(1)
        self.remain -= 1
        return int(r)

    def update_couple(self, inner):
        left_idx, right_idx = self.convert_idx(inner)
        lv, rv = self.ask(left_idx), self.ask(right_idx)
        if lv == rv:
            self.last_same = inner
        if lv != rv:
            self.last_diff = inner
        self.left.append(lv)
        self.right.append(rv)

    def right_query(self, inner):
        _, right_idx = self.convert_idx(inner)
        return self.ask(right_idx)

    def fill_round(self):
        size = len(self.left)
        limit = min(size + self.remain // 2, self.n // 2)
        for i in range(size, limit):
            self.update_couple(i)


def check_verdict(ans):
    print(ans)
    verdict = input()
    if verdict == 'Y':
        return
    elif verdict == 'N':
        print('returned verdict is N, Wrong answer', file=sys.stderr)
        exit(1)
    else:
        assert False, 'Incorrect verdict: {}'.format(verdict)


def solve_n(n):
    fra = FlipReverseArray(n)
    fra.fill_round()

    while fra.size() < n:
        fra.orient()
        fra.fill_round()
    ans = ''.join(str(i) for i in fra.value())
    check_verdict(ans)


def solve_10():
    result = ''
    for i in range(10):
        print(i+1)
        r = input()
        if r not in ('0', '1'):
            assert False, 'Incorrect return: {}'.format(r)
            exit(1)
        result += r
    check_verdict(result)


def solve(b):
    if b == 10:
        solve_10()
    elif b == 20:
        solve_n(20)
    elif b == 100:
        solve_n(100)
    else:
        assert False, 'b is incorrect, {}'.format(b)


def main():
    t, b = [int(x) for x in input().split()]

    for _ in range(t):
        solve(b)


if __name__ == '__main__':
    main()
