class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        i = 0
        n = len(arr)

        result = 0
        while i < n - 1:
            while i < n - 1 and arr[i] >= arr[i+1]:
                i += 1
            start = i
            while i < n - 1 and arr[i] < arr[i+1]:
                i += 1
            mid = i
            while i < n - 1 and arr[i] > arr[i+1]:
                i += 1
            end = i

            if start < mid and mid < end:
                result = max(result, end - start + 1)
        return result
