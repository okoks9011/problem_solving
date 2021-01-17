class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        m = len(costs)
        n = m // 2
        costs.sort(key=lambda c: c[0] - c[1])
        result = 0
        for c in costs[:n]:
            result += c[0]
        for c in costs[n:]:
            result += c[1]
        return result
