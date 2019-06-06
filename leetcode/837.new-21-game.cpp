#include <vector>

using namespace std;

class Solution {
  public:
    double new21Game(int n, int k, int w) {
        if (n < k)
            return 0.0;

        vector<double> prob(k+w);
        prob[0] = 1.0;
        for (int i = 0; i < k; ++i) {
            for (int j = 1; j <= w; ++j)
                prob[i+j] += prob[i] / w;
        }

        double result = 0.0;
        for (int i = k; i <= n && i < k+w; ++i)
            result += prob[i];
        return result;
    }
};
