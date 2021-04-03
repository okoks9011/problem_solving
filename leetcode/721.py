import bisect


class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        names = []
        mails = {}
        for account in accounts:
            assert len(account) >= 2
            name = account[0]
            found = -1
            for email in account[1:]:
                if email in mails:
                    found = mails[email]
                    break
            if found == -1:
                found = len(names)
                names.append(name)

            assert names[found] == name
            for email in account[1:]:
                mails[email] = found

        result = [[] for _ in names]
        for email, idx in mails.items():
            bisect.insort(result[idx], email)
        for i, name in enumerate(names):
            result[i].insert(0, name)

        return result
