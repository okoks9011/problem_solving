class Solution:
    def __init__(self):
        self.result = set()
        self.max_len = 0

    def update(self, candi):
        if len(candi) < self.max_len:
            return

        if len(candi) > self.max_len:
            self.max_len = len(candi)
            self.result.clear()
        self.result.add(candi)

    def removeInvalidParentheses(self, s: str) -> List[str]:
        def dfs(i, cur, bal):
            if bal < 0:
                return
            if i == len(s):
                if bal == 0:
                    self.update(''.join(cur))
                return

            si = s[i]

            if si.isalpha():
                cur.append(si)
                dfs(i+1, cur, bal)
                cur.pop()
                return

            assert si == '(' or si == ')'
            cur.append(si)
            new_bal = bal + (1 if si == '(' else -1)
            dfs(i+1, cur, new_bal)
            cur.pop()

            dfs(i+1, cur, bal)

        dfs(0, [], 0)
        return list(self.result)
