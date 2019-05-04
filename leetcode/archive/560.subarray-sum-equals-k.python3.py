class Solution:
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        counts = 0
        acc = 0
        acc_dic = {}
        acc_dic[0] = 1

        for n in nums:
            acc += n
            counts += acc_dic.get(acc - k, 0)
            acc_dic[acc] = acc_dic.get(acc, 0) + 1

        return counts
