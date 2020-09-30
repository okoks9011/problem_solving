#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;

const int kMax = 987654321;

class Solution {
  public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_acc(n+1, kMax);
        unordered_map<int, int> loc;
        int sum = 0;
        loc[sum] = 0;

        int ans = kMax;
        for (int i = 1; i <= n; ++i) {
            sum += arr[i-1];
            auto it = loc.find(sum - target);
            if (it != loc.end()) {
                ans = min(ans, i - it->second + min_acc[it->second]);
                min_acc[i] = i - it->second;
            }
            min_acc[i] = min(min_acc[i], min_acc[i-1]);
            loc[sum] = i;
        }

        if (ans == kMax)
            return -1;
        else
            return ans;
    }
};
