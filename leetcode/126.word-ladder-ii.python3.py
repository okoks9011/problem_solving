from collections import namedtuple
from collections import deque

Triple = namedtuple('Triple', ['word', 'candi', 'history'])

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
        s = Triple(beginWord, set(wordList), [beginWord])
        cur_q = deque()
        next_q = deque()
        cur_q.append(s)
        while cur_q:
            if any(map(lambda x: x.word == endWord, cur_q)):
                target = filter(lambda x: x.word == endWord, cur_q)
                return list(map(lambda x: x.history, target))
            while cur_q:
                t = cur_q.popleft()
                for c_word in t.candi:
                    if adjcent_word(t.word, c_word):
                        new_candi = t.candi.copy()
                        new_candi.remove(c_word)
                        new_history = t.history.copy()
                        new_history.append(c_word)
                        next_q.append(Triple(c_word, new_candi, new_history))
            cur_q, next_q = next_q, cur_q
        return []
