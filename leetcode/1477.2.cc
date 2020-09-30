#include <vector>
#include <algorithm>


using namespace std;


const int kMax = 987654321;

class Solution {
  public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> acc(n+1);
        for (int i = 0; i < n; ++i)
            acc[i+1] = acc[i] + arr[i];

        vector<int> min_acc(n+1, kMax);
        int ans = kMax;
        int left = 0;
        for (int right = 1; right <= n; ++right) {
            while (acc[right] - acc[left] > target)
                ++left;

            if (acc[right] - acc[left] == target) {
                ans = min(ans, right - left + min_acc[left]);
                min_acc[right] = right - left;
            }
            min_acc[right] = min(min_acc[right], min_acc[right-1]);
        }

        if (ans == kMax)
            return -1;
        else
            return ans;
    }
};
