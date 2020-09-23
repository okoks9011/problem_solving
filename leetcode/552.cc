#include <iostream>


using namespace std;


const int kMod = 1000000007;

class Solution {
  public:
    int checkRecord(int n) {
        vector<int> dpl(n+1);
        vector<int> dpp(n+1);

        dpp[0] = 1;
        dpp[1] = 1;
        dpl[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dpp[i] = (dpp[i-1] + dpl[i-1]) % kMod;
            dpl[i] = (dpp[i-1] + dpp[i-2]) % kMod;
        }

        vector<int> dplp(n+1);
        for (int i = 0; i <= n; ++i)
            dplp[i] = (dpl[i] + dpp[i]) % kMod;

        int result = dplp[n];
        for (int i = 0; i < n; ++i) {
            result += (1LL * dplp[i] * dplp[n-1-i]) % kMod;
            result %= kMod;
        }
        return result;
    }
};
