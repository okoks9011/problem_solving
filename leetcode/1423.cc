#include <vector>
#include <limits>
#include <algorithm>
#include <numeric>


using namespace std;


class Solution {
  public:
    int maxScore(vector<int>& cardPoints, int k) {
        int cur_sum = 0;
        int t = cardPoints.size() - k;
        for (int i = 0; i < t-1; ++i)
            cur_sum += cardPoints[i];

        int min_sum = numeric_limits<int>::max();
        if (t >= 1) {
            for (int i = t-1; i < cardPoints.size(); ++i) {
                cur_sum += cardPoints[i];
                min_sum = min(min_sum, cur_sum);
                cur_sum -= cardPoints[i-t+1];
            }
        } else {
            min_sum = 0;
        }

        int total_sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        return total_sum - min_sum;
    }
};
