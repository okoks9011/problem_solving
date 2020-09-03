#include <vector>
#include <algorithm>


using namespace std;


class Solution {
  public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> acc(n+1);
        for (int i = 0; i < n; ++i)
            acc[i+1] = acc[i] + cardPoints[i];

        int result = 0;
        for (int i = 0; i <= k; ++i)
            result = max(result, acc[i] - acc[n-k+i] + acc[n]);
        return result;
    }
};
