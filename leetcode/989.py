class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        carry = 0
        i = len(A) - 1
        result = []
        while i >= 0 or K > 0 or carry > 0:
            d = carry + (K % 10) + (A[i] if i >= 0 else 0)
            result.append(d % 10)

            carry = d // 10
            K //= 10
            i -= 1

        result.reverse()
        return result
