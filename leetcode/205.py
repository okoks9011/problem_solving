class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        dic = {}
        for si, ti in zip(s, t):
            if si in dic:
                if dic[si] != ti:
                    return False
            else:
                dic[si] = ti

        if len(dic) != len(set(dic.values())):
            return False
        return True
