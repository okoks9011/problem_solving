from collections import Counter


def include(a_cnt, b_cnt):
    for bk, bv in b_cnt.items():
        if a_cnt[bk] < bv:
            return False
    return True


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        tail = 0
        t_cnt = Counter(t)
        w_cnt = Counter()

        min_size = int(10e5) + 1
        result = ''

        for head in range(len(s)):
            w_cnt[s[head]] += 1
            while include(w_cnt, t_cnt) > 0 and tail <= head:
                new_size = head - tail + 1
                if new_size < min_size:
                    min_size = new_size
                    result = s[tail:head+1]
                w_cnt[s[tail]] -= 1
                tail += 1

        return result
