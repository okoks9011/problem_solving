from collections import Counter


class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls = 0
        cows = 0
        cnt = Counter()
        for s, g in zip(secret, guess):
            if s == g:
                bulls += 1
                continue

            if cnt[s] < 0:
                cows += 1
            if cnt[g] > 0:
                cows += 1
            cnt[s] += 1
            cnt[g] -= 1

        return f'{bulls}A{cows}B'
