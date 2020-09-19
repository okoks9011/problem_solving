#include <vector>
#include <algorithm>


using namespace std;

const int kMax = 987654321;


class Solution {
  public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> pre(n, kMax);
        vector<int> suf(n, kMax);
        int sum = 0;
        int tail = 0;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            while (tail <= i && sum > target) {
                sum -= arr[tail];
                ++tail;
            }
            if (sum == target) {
                int len = i - tail + 1;
                pre[i] = len;
                suf[i-len+1] = len;
            }
        }

        vector<int> suf_acc(n, kMax);
        suf_acc[n-1] = suf[n-1];
        for (int i = n - 2; i >= 0; --i)
            suf_acc[i] = min(suf_acc[i+1], suf[i]);

        int acc = kMax;
        int result = kMax;
        for (int i = 0; i < n - 1; ++i) {
            acc = min(acc, pre[i]);
            int cur_result = acc + suf_acc[i+1];
            result = min(result, cur_result);
        }

        if (result >= kMax)
            return -1;
        else
            return result;
    }
};
