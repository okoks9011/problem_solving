from collections import namedtuple
from collections import deque

def gen_all_path(total, beginWord, endWord):
    if beginWord == endWord:
        return [[beginWord]]
    result = []
    for e in total[endWord]:
        e_paths = gen_all_path(total, beginWord, e)
        for e_path in e_paths:
            e_path.append(endWord)
            result.append(e_path)
    return result

def adjcent_word(A, B):
    return 1 == sum(1 for a, b in zip(A,B) if a != b)

class Solution:
    def findLadders(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """
        candi = set(wordList)
        cur = {}
        nextt = {}
        total = {}
        cur[beginWord] = None
        while cur:
            if endWord in cur:
                 return gen_all_path(total, beginWord, endWord)
            for t_word in cur:
                for c_word in candi:
                    if adjcent_word(t_word, c_word):
                        if c_word not in nextt:
                            nextt[c_word] = []
                        nextt[c_word].append(t_word)
            for i_word in nextt:
                if i_word in candi:
                    candi.remove(i_word)
            total.update(nextt)
            cur = nextt
            nextt = {}
        return []
