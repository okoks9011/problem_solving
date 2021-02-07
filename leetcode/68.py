class Solution:
    def fullJustify(self, words: List[str], max_width: int) -> List[str]:
        lines = []
        cur_len = 0
        for word in words:
            if not lines or (cur_len + 1 + len(word)) > max_width:
                lines.append([])
                cur_len = len(word)
            else:
                cur_len += 1 + len(word)
            lines[-1].append(word)

        printed = []
        for line in lines[:-1]:
            spaces = max_width - sum(len(w) for w in line)
            if len(line) == 1:
                printed.append(line[0] + ' ' * spaces)
                continue

            pad_size = spaces // (len(line) - 1)
            extra =  spaces % (len(line) - 1)
            cur_printed = ''
            for i, word in enumerate(line[:-1]):
                cur_printed += word + ' ' * pad_size
                if i < extra:
                    cur_printed += ' '
            cur_printed += line[-1]
            printed.append(cur_printed)

        last_printed = ' '.join(lines[-1]).ljust(max_width)
        printed.append(last_printed)
        return printed
