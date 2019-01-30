#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class FriendScore {
  public:
    int highestScore(vector<string> friends) {
        int n = friends.size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (friends[i][j] == 'Y') {
                    ++cur;
                } else {
                    for (int k = 0; k < n; ++k) {
                        if (friends[i][k] == 'Y' && friends[j][k] == 'Y') {
                            ++cur;
                            break;
                        }
                    }
                }
            }
            result = max(result, cur);
        }
        return result;
    }
};
