class Solution:
    def tilingRectangle(self, n: int, m: int) -> int:
        self.result = m * n

        def dfs(state, cnt):
            if cnt >= self.result:
                return

            min_v = min(state)
            if min_v == n:
                self.result = min(self.result, cnt)
                return

            start = state.index(min_v)
            right = start
            while right < m and min_v == state[right]:
                right += 1

            for w in range(min(right-start, n-min_v), 0, -1):
                new_state = state[:start] + (min_v+w,) * w + state[start+w:]
                dfs(new_state, cnt+1)

        dfs((0,) * m, 0)
        return self.result
