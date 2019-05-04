class Solution:
    def numRescueBoats(self, people, limit):
        people.sort()
        counts = 0
        light, heavy = 0, len(people) - 1

        while light <= heavy:
            if light == heavy:
                counts += 1
                break
            if people[light] + people[heavy] <= limit:
                light += 1
            heavy -= 1
            counts += 1

        return counts
