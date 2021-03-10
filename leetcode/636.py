class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        def parse(log):
            raw = log.split(':')
            return int(raw[0]), raw[1], int(raw[2])

        stack, last_time = [], 0
        acc = [0] * n
        for log in logs:
            fid, tag, time = parse(log)
            if not stack:
                assert tag == 'start'
                stack.append(fid)
                last_time = time
                continue

            last_fid = stack[-1]
            if tag == 'start':
                acc[last_fid] += time - last_time
                stack.append(fid)
            elif tag == 'end' and last_fid == fid:
                time += 1
                acc[last_fid] += time - last_time
                stack.pop()
            else:
                assert False

            last_time = time

        return acc
