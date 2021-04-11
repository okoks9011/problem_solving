class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        n = len(num)
        result = []
        def dfs(i, cur):
            cur.append(num[i])
            if i == n-1:
                s = ''.join(cur)
                for c in re.split(r'[^\d]+', s):
                    if c != str(int(c)):
                        cur.pop()
                        return
                try:
                    if eval(s) == target:
                        result.append(s)
                except:
                    pass
            else:
                for op in ['', '*', '+', '-']:
                    cur.append(op)
                    dfs(i+1, cur)
                    cur.pop()
            cur.pop()

        dfs(0, [])
        return result
