import functools


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)

        @functools.lru_cache(None)
        def cal_distance(i, j):
            if i == n:
                return m - j
            if j == m:
                return n - i

            if word1[i] == word2[j]:
                return cal_distance(i+1, j+1)
            else:
                return 1 + min(
                    cal_distance(i, j+1),
                    cal_distance(i+1, j),
                    cal_distance(i+1, j+1)
                )
        return cal_distance(0, 0)
