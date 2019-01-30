#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

class FriendScore {
  public:
    int highestScore(vector<string> friends) {
        int result = 0;
        int n = friends.size();
        for (int i = 0; i < n; ++i) {
            deque<bool> f(n);
            for (int j = 0; j < n; ++j) {
                if (friends[i][j] != 'Y')
                    continue;
                f[j] = true;
                for (int k = 0; k < n; ++k) {
                    if (friends[j][k] != 'Y')
                        continue;
                    f[k] = true;
                }
            }
            f[i] = false;
            result = max(result, static_cast<int>(count(f.begin(), f.end(), true)));
        }
        return result;
    }
};
