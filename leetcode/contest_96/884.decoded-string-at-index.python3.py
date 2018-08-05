class Solution:
    def decodedAtIndex(self, S, K):
        trail = []
        i = 0
        for s in S:
            trail.append((s, i))
            if s.isalpha():
                i += 1
            else:  # s is digit
                i *= int(s)

        K = K - 1  # kth index is [k-1]
        for s, i in reversed(trail):
            if s.isdigit():
                K %= i
            else:  # s is alpha
                if i == K:
                    return s
