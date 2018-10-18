import string
from collections import defaultdict


class Solution:
    def __init__(self):
        self.c = 0

    def is_incidient(self, a, b):
        c = 0
        for i, j in zip(a, b):
            if i != j:
                c += 1
                if c > 1:
                    return False
            return True

    def findLadders(self, beginWord, endWord, wordList):
        s = set(wordList)
        c = 1
        d = defaultdict(list)
        d[beginWord] = [[beginWord]]
        s.discard(beginWord)

        q = {beginWord}
        while len(q) > 0:
            r = set()
            for i in q:
                if i == endWord:
                    return d[i]
                for j in range(len(i)):
                    for ch in string.ascii_lowercase:
                        t = i[:j] + ch + i[j + 1:]
                        if t in s:
                            r.add(t)
                            d[t].extend(x + [t] for x in d[i])
            for i in r:
                s.remove(i)
            q = r
            c += 1
        return []
