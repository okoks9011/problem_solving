#include <vector>
#include <algorithm>


using namespace std;


class Solution {
  public:
    int maxSumTwoNoOverlap(vector<int>& a, int l, int m) {
        int n = a.size();
        vector<int> acc(n+1);
        for (int i = 0; i < n; ++i)
            acc[i+1] = acc[i] + a[i];

        vector<int> l_sum_l(n+1);
        for (int i = l; i <= n; ++i) {
            int cur = acc[i] - acc[i-l];
            l_sum_l[i] = max(l_sum_l[i-1], cur);
        }

        vector<int> l_sum_r(n+1);
        for (int i = n-l; i >= 0; --i) {
            int cur = acc[i+l] - acc[i];
            l_sum_r[i] = max(l_sum_r[i+1], cur);
        }

        int result = 0;
        for (int i = m; i <= n; ++i) {
            int m_sum = acc[i] - acc[i-m];
            result = max(result, l_sum_l[i-m] + m_sum);
            result = max(result, m_sum + l_sum_r[i]);
        }
        return result;
    }
};
