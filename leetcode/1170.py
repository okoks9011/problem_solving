import bisect


class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        def f(s):
            return s.count(min(s))

        applied_words = [f(w) for w in words]
        applied_words.sort()
        n = len(applied_words)
        result = []
        for q in queries:
            applied_query = f(q)
            result.append(n - bisect.bisect_right(applied_words, applied_query))
        return result
