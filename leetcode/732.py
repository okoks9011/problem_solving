class MyCalendarThree:
    def __init__(self):
        self.books = []

    def book(self, start: int, end: int) -> int:
        self.books.append((start, end))
        return self.cal_overlap()

    def cal_overlap(self):
        points = set()
        for start, end in self.books:
            points.add(start)
            points.add(end)
        dic = { ori: i for i, ori in enumerate(sorted(points)) }

        acc = [0] * len(points)
        for start, end in self.books:
            acc[dic[start]] += 1
            acc[dic[end]] -= 1
        for i in range(1, len(acc)):
            acc[i] += acc[i-1]
        return max(acc)


# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(start,end)
