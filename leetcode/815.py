import collections


class Solution:
    def numBusesToDestination(self, routes: List[List[int]], S: int, T: int) -> int:
        if S == T:
            return 0

        stops = collections.defaultdict(set)
        for bi, route in enumerate(routes):
            for ri in route:
                stops[ri].add(bi)

        r = len(routes)
        adjs = [[False] * r for _ in range(r)]
        for group in stops.values():
            g = len(group)
            if g <= 1:
                continue
            group_list = list(group)
            for i in range(g):
                for j in range(i+1, g):
                    adjs[group_list[i]][group_list[j]] = True
                    adjs[group_list[j]][group_list[i]] = True

        cur_q = list(stops[S])
        visited = set(cur_q)
        goal = stops[T]
        level = 1
        while cur_q:
            next_q = []
            for bi in cur_q:
                if bi in goal:
                    return level
                for bj in range(r):
                    if not adjs[bi][bj] or bj in visited:
                        continue
                    visited.add(bj)
                    next_q.append(bj)
            cur_q = next_q
            level += 1

        return -1
