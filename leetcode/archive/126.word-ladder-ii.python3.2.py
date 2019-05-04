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
        v = set()
        c = 1
        A = set('abcdefghijklmnopqrstuvwxyz')
        q = [[beginWord, []]]
        answer = []
        while len(q) > 0 and self.c == 0:
            r = []
            for i, l in q:
                v.add(i)
                if i == endWord:
                    self.c = c
                    l = l.copy()
                    l.append(i)
                    answer.append(l)
                    continue

                l = l.copy()
                l.append(i)
                for j in range(len(i)):
                    for ch in A:
                        t = i[:j] + ch + i[j + 1:]
                        if (t in s) and t not in v:
                            r.append([t, l])
            q = r
            c += 1
        return answer
