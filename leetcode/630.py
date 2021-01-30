import heapq


class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda x: x[1])
        max_pq = []
        cur = 0

        for t, d in courses:
            cur += t
            heapq.heappush(max_pq, -t)

            if cur > d:
                max_t = -heapq.heappop(max_pq)
                cur -= max_t

        return len(max_pq)
