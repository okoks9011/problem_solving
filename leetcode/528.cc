#include <vector>
#include <algorithm>
#include <random>


using namespace std;


class Solution {
  private:
    vector<int> acc;
    mt19937 rng;
    uniform_int_distribution<int> dis;

  public:
    Solution(vector<int>& w) {
        int n = w.size();
        acc = vector<int>(n);

        acc[0] = w[0];
        for (int i = 1; i < w.size(); ++i)
            acc[i] = acc[i-1] + w[i];

        random_device rd;
        rng = mt19937(rd());
        dis = uniform_int_distribution<>(1, acc.back());
    }

    int pickIndex() {
        int pick = dis(rng);
        auto it = lower_bound(acc.begin(), acc.end(), pick);
        assert(it != acc.end());

        return it - acc.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
