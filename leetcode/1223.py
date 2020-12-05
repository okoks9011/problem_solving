class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        max_v = max(rollMax)
        mod = 1_000_000_007

        cur = [[0] * (max_v + 1) for _ in range(6)]
        for di in range(6):
            cur[di][1] = 1

        for _ in range(n-1):
            next_ = [[0] * (max_v + 1) for _ in range(6)]
            for di, conti in enumerate(cur):
                for cnt, value in enumerate(conti):
                    if cnt == 0:
                        continue
                    for ni in range(6):
                        if di == ni:
                            continue
                        next_[ni][1] += value
                        next_[ni][1] %= mod
                    if cnt < rollMax[di]:
                        next_[di][cnt+1] += value
                        next_[di][cnt+1] %= mod
            cur = next_
        return sum(sum(conti) for conti in cur) % mod
