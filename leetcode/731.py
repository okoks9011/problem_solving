def check_overlapped(inter, s, e):
    s_old, e_old = inter
    return s_old < e and s < e_old

def get_overlapped(inter, s, e):
    s_new = max(inter[0], s)
    e_new = min(inter[1], e)
    if s_new < e_new:
        return (s_new, e_new)
    else:
        return None

class MyCalendarTwo:

    def __init__(self):
        self.inters = []
        self.overlapped = []

    def book(self, start: int, end: int) -> bool:
        for over in self.overlapped:
            if check_overlapped(over, start, end):
                return False

        for inter in self.inters:
            over = get_overlapped(inter, start, end)
            if over is not None:
                self.overlapped.append(over)
        self.inters.append((start, end))
        return True



# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)
