#include <limits>
#include <algorithm>

using namespace std;

class Solution {
  public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size())
            return findMedianSortedArrays(b, a);

        int half = (a.size()+b.size()+1) / 2;
        int left = 0;
        int right = a.size();
        while (left <= right) {
            int pref_a = (right-left) / 2 + left;
            int pref_b = half - pref_a;

            int max_pref_a = pref_a == 0 ? numeric_limits<int>::min() : a[pref_a-1];
            int min_suf_a = pref_a == a.size() ? numeric_limits<int>::max() : a[pref_a];
            int max_pref_b = pref_b == 0 ? numeric_limits<int>::min() : b[pref_b-1];
            int min_suf_b = pref_b == b.size() ? numeric_limits<int>::max() : b[pref_b];

            if (max_pref_a <= min_suf_b && max_pref_b <= min_suf_a) {
                if ((a.size()+b.size()) % 2) {
                    return max(max_pref_a, max_pref_b);
                } else {
                    int max_pref = max(max_pref_a, max_pref_b);
                    int min_suf = min(min_suf_a, min_suf_b);
                    return (max_pref+min_suf) / 2.0;
                }
            } else if (max_pref_a > min_suf_b) {
                right = pref_a - 1;
            } else if (max_pref_b > min_suf_a) {
                left = pref_a + 1;
            } else {
                assert(false);
            }
        }
        assert(false);
    }
};
