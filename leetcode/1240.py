import functools


class Solution:
    def tilingRectangle(self, n: int, m: int) -> int:
        @functools.lru_cache(None)
        def dfs(state):
            min_v = min(state)
            if min_v == n:
                return 0

            start = state.index(min_v)
            result = float('inf')

            for end in range(start, m):
                if state[start] != state[end]:
                    break
                w = end - start + 1
                if state[start] + w > n:
                    break
                new_state = state[:start] + (state[start]+w,) * w + state[end+1:]
                result = min(result, dfs(new_state)+1)
            return result

        return dfs((0,) * m)
