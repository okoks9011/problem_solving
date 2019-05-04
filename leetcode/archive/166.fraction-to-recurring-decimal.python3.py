class Solution:
    def fractionToDecimal(self, numer, denom):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """

        num_str = []
        if numer * denom < 0:
            num_str.append('-')
        numer = abs(numer)
        denom = abs(denom)

        if numer // denom:
            num_str.append(str(numer // denom))
        else:
            num_str.append('0')

        if numer % denom:
            num_str.append('.')
            numer %= denom
            index = {}
            trail = []

            while True:
                if numer in index:
                    non_repeat = ''.join(map(str, trail[:index[numer]]))
                    num_str.append(non_repeat)
                    repeat = ''.join(map(str, trail[index[numer]:]))
                    num_str.extend(['(', repeat, ')'])
                    break
                elif numer == 0:
                    num_str.extend(map(str, trail))
                    break

                n = numer * 10
                qoutient = n // denom
                index[numer] = len(trail)
                trail.append(qoutient)
                numer = n % denom

        return ''.join(num_str)
