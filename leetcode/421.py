class TrieNode:
    def __init__(self):
        self.child = [None, None]

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, s):
        cur = self.root
        for si in s:
            if not cur.child[si]:
                cur.child[si] = TrieNode()
            cur = cur.child[si]

    def find_max_xor(self, s):
        cur = self.root
        result = 0
        for si in s:
            pair = 0 if si else 1
            result *= 2
            if cur.child[pair]:
                result += 1
                cur = cur.child[pair]
            else:
                cur = cur.child[si]
        return result


class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        size = max(len(bin(ni)) for ni in nums) - 2
        bins = []
        for ni in nums:
            x = bin(ni)[2:]
            x_fit = '0' * (size - len(x)) + x
            bins.append([int(xi) for xi in x_fit])

        t = Trie()
        for bi in bins:
            t.insert(bi)

        result = 0
        for bi in bins:
            result = max(result, t.find_max_xor(bi))
        return result
