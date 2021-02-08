import enum


class Color(enum.Enum):
    WHITE = 0
    GRAY = 1
    BLACK = 2


class Solution:
    def topological_sort(self, adjs):
        n = len(adjs)
        visited = [Color.WHITE] * n
        order = []

        def dfs(u):
            visited[u] = Color.GRAY
            for v in adjs[u]:
                if visited[v] == Color.BLACK:
                    continue
                elif visited[v] == Color.GRAY:
                    return False

                if not dfs(v):
                    return False
            visited[u] = Color.BLACK
            order.append(u)

            return True

        for s in reversed(range(n)):
            if visited[s] == Color.BLACK:
                continue
            assert visited[s] == Color.WHITE
            if not dfs(s):
                return None
        return order

    def sortItems(self, n: int, m: int, group: List[int], before_items: List[List[int]]) -> List[int]:
        def get_innode(i):
            return n + 2 * i

        def get_outnode(i):
            return n + 2 * i + 1

        adjs = [[] for _ in range(n + 2 * m)]
        for i, gi in enumerate(group):
            if gi == -1:
                continue
            adjs[get_innode(gi)].append(i)
            adjs[i].append(get_outnode(gi))

        for i, befores in enumerate(before_items):
            gi = group[i]
            for b in befores:
                gb = group[b]
                if gi == gb:
                    adjs[i].append(b)
                else:
                    from_node = get_outnode(gi) if gi != -1 else i
                    to_node = get_innode(gb) if gb != -1 else b
                    adjs[from_node].append(to_node)

        result = self.topological_sort(adjs)
        if result is None:
            return []

        return [x for x in result if x < n]
