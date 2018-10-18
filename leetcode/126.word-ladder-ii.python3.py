import string

def gen_adjcent(word):
    for i in range(len(word)):
        for c in string.ascii_lowercase:
            yield word[:i] + c + word[i+1:]

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
        cur[beginWord] = [[beginWord]]
        while cur:
            if endWord in cur:
                 return cur[endWord]
            for t_word in cur:
                for c_word in gen_adjcent(t_word):
                    if c_word in candi:
                        if c_word not in nextt:
                            nextt[c_word] = []
                        nextt[c_word].extend(t_path + [c_word] for t_path in cur[t_word])
            candi -= set(nextt)
            cur = nextt
            nextt = {}
        return []
