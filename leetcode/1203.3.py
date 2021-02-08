from collections import deque


class Solution:
    def topological_sort(self, adjs):
        n = len(adjs)
        ind = [0] * n

        for u, adj in enumerate(adjs):
            for v in adj:
                ind[v] += 1

        order = []
        q = deque(v for v in range(n) if ind[v] == 0)
        while q:
            cur = q.popleft()
            order.append(cur)
            for w in adj[cur]:
                ind[w] -= 1
                if ind[w] == 0:
                    q.append(w)
        return order if len(order) == n else []

    def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
        for i in range(n):
            if group[i] == -1:
                group[i] = m
                m += 1

        item_order = self.topological_sort(beforeItems)
        if item_order is None:
            return []
        item_order.reverse()

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
        group_order.reverse()

        group_loc = [-1] * m
        for i, v in enumerate(group_order):
            group_loc[v] = i

        return sorted(range(n), key=lambda x: (group_loc[group[x]], item_loc[x]))
