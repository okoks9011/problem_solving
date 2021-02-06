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

        for s in range(n):
            if visited[s] == Color.BLACK:
                continue
            assert visited[s] == Color.WHITE

            if not dfs(s):
                return None
        return order

    def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
        for i in range(n):
            if group[i] == -1:
                group[i] = m
                m += 1

        item_order = self.topological_sort(beforeItems)
        if item_order is None:
            return []

        item_loc = [-1] * n
        for i, v in enumerate(item_order):
            item_loc[v] = i

        before_groups = [[] for _ in range(m)]
        for i, before in enumerate(beforeItems):
            gi = group[i]
            for b in before:
                gb = group[b]
                if gi != gb:
                    before_groups[gi].append(gb)
        group_order = self.topological_sort(before_groups)
        if group_order is None:
            return []

        group_loc = [-1] * m
        for i, v in enumerate(group_order):
            group_loc[v] = i

        return sorted(range(n), key=lambda x: (group_loc[group[x]], item_loc[x]))
