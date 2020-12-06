import sortedcontainers


class MyCalendarThree:
    def __init__(self):
        self.books = sortedcontainers.SortedDict()

    def book(self, start: int, end: int) -> int:
        self.books[start] = self.books.get(start, 0) + 1
        self.books[end] = self.books.get(end, 0) - 1
        acc = 0
        result = 0
        for k, v in self.books.items():
            acc += v
            result = max(result, acc)
        return result


# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(start,end)
