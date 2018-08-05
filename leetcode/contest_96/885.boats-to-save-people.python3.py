# Time limit exceed

class Solution:
    def numRescueBoats(self, people, limit):
        people.sort()
        result = 0
        while people:
            cur_max = people.pop()
            pair = limit - cur_max
            i = next((i for i, p in enumerate(reversed(people)) if p <= pair), None)
            if i is not None:
                people.pop(len(people) - 1 - i)
            result += 1
        return result
