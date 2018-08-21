import enum
from collections import defaultdict
from collections import deque

class Color(enum.Enum):
    BLACK = 1
    RED = 2

class Solution:
    def possibleBipartition(self, N, dislikes):
        """
        :type N: int
        :type dislikes: List[List[int]]
        :rtype: bool
        """
        B, R = Color.BLACK, Color.RED
        g = defaultdict(list)
        colors = [None] * (N + 1)

        for f, t in dislikes:
            g[f].append(t)
            g[t].append(f)

        q = deque([])
        for f in g:
            if colors[f]:
                continue
            q.append((f, B))
            while q:
                v, c = q.popleft()
                if not colors[v]:
                    colors[v] = c
                    next_c = R if c == B else B
                    if v not in g:
                        continue
                    for t in g[v]:
                        if not colors[t]:
                            q.append((t, next_c))
                        elif colors[t] != next_c:
                            return False
                elif colors[v] != c:
                    return False
        return True
