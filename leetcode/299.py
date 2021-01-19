import string
from collections import Counter


class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls = 0
        s_cnt = Counter()
        g_cnt = Counter()
        for s, g in zip(secret, guess):
            if s == g:
                bulls += 1
                continue
            s_cnt[s] += 1
            g_cnt[g] += 1
        cows = 0
        for d in string.digits:
            cows += min(s_cnt[d], g_cnt[d])
        return f'{bulls}A{cows}B'
