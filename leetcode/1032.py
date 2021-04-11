from collections import defaultdict


class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.is_leaf = False

def insert(node, word):
    cur = node
    for c in word:
        cur = cur.children[c]
    cur.is_leaf = True

def find(node, chars):
    cur = node
    for c in reversed(chars):
        if c not in cur.children:
            return False
        cur = cur.children[c]
        if cur.is_leaf:
            return True
    return False

class StreamChecker:
    def __init__(self, words: List[str]):
        self.history = []
        self.root = TrieNode()
        for word in words:
            insert(self.root, word[::-1])

    def query(self, letter: str) -> bool:
        self.history.append(letter)
        return find(self.root, self.history)


# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)
