from collections import defaultdict

g = defaultdict(set)
n, m = map(int, input().split())
c = [0] + list(map(int, input().split()))
colors = set(c[1:])
for _ in range(m):
    a, b = map(int, input().split())
    g[a].add(b)
    g[b].add(a)

diversity = defaultdict(set)
visited = set()
def bfs(v):
    if v in visited:
        return
    q = [v]
    visited.add(v)
    while q:
        nq = []
        for e in q:
            color = c[e]

            for ne in g[e]:
                new_color = c[ne]
                if new_color != color:
                    diversity[new_color].add(color)
                    diversity[color].add(new_color)
                if ne not in visited:
                    visited.add(ne)
                    nq.append(ne)
        q = nq

for i in range(1, n+1):
    bfs(i)

max_color = min(colors)
for color in colors:
    if len(diversity[color]) > len(diversity[max_color]):
        max_color = color
    elif len(diversity[color]) == len(diversity[max_color]):
        max_color = min(max_color, color)
print(max_color)
