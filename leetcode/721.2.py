import bisect
from collections import defaultdict


class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))

    def union(self, v, u):
        pv, pu = self.find(v), self.find(u)
        self.parent[pv] = pu

    def find(self, v):
        if self.parent[v] == v:
            return v
        self.parent[v] = self.find(self.parent[v])
        return self.parent[v]


class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        assert accounts
        loc, names, mails = {}, [], []
        groups = []
        for account in accounts:
            assert account
            name = account[0]
            acc_mails = account[1:]
            assert acc_mails

            group = []
            for acc_mail in acc_mails:
                if not acc_mail in loc:
                    loc[acc_mail] = len(mails)
                    mails.append(acc_mail)
                    names.append(name)
                group.append(loc[acc_mail])
            groups.append(group)

        m = len(mails)
        ds = DisjointSet(m)
        for group in groups:
            if len(group) <= 1:
                continue
            for i in range(1, len(group)):
                ds.union(group[i-1], group[i])

        same_accounts = defaultdict(list)
        for i in range(m):
            p = ds.find(i)
            bisect.insort(same_accounts[p], mails[i])
        return [[names[k]] + v for k, v in same_accounts.items()]
