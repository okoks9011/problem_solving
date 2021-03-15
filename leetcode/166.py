class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return '0'
        neg = False
        if numerator * denominator < 0:
            neg = True
        n, d = abs(numerator), abs(denominator)

        decimal = n // d
        n %= d

        points, loc = [], {}
        while n and n not in loc:
            loc[n] = len(points)
            n *= 10
            points.append(n // d)
            n %= d

        result = str(decimal)
        if neg:
            result = '-' + result
        if points:
            repeat = ''
            if n in loc:
                repeat = '(' + ''.join(str(c) for c in points[loc[n]:]) + ')'
                points = points[:loc[n]]
            result += '.' + ''.join(str(c) for c in points) + repeat
        return result
