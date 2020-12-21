import collections


class Solution:
    def numBusesToDestination(self, routes: List[List[int]], S: int, T: int) -> int:
        stops = collections.defaultdict(set)

        for bi, route in enumerate(routes):
            for ri in route:
                stops[ri].add(bi)
        return -1
