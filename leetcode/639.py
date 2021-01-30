class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = 1
        if s[0] == '*':
            dp[1] = 9
        elif '1' <= s[0] <= '9':
            dp[1] = 1

        mod_v = int(10e9 + 7)
        for i in range(2, n + 1):
            single_times = 0
            if s[i-1] == '*':
                single_times = 9
            elif '1' <= s[i-1] <= '9':
                single_times = 1
            dp[i] = dp[i-1] * single_times
            dp[i] %= mod_v

            times = 0
            if s[i-2] == '*' and s[i-1] == '*':
                times = 15
            elif s[i-2] == '*':
                if '0' <= s[i-1] <= '6':
                    times = 2
                else:
                    times = 1
            elif s[i-1] == '*':
                if s[i-2] == '1':
                    times = 9
                elif s[i-2] == '2':
                    times = 6
            else:
                 if 10 <= int(s[i-2:i]) <= 26:
                    times = 1
            dp[i] += dp[i-2] * times
            dp[i] %= mod_v

        return dp[n]
