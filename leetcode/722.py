class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        block = False
        result = []
        buf = ''

        for line in source:
            i = 0
            t = len(line)
            while i < t:
                if not block:
                    if i < t - 1 and line[i:i+2] == '//':
                        break
                    elif i < t - 1 and line[i:i+2] == '/*':
                        block = True
                        i += 1
                    else:
                        buf += line[i]
                else:
                    if i < t - 1 and line[i:i+2] == '*/':
                        block = False
                        i += 1
                i += 1
            if not block and buf:
                result.append(buf)
                buf = ''
        return result
