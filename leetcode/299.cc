#include <vector>
#include <string>


using namespace std;


class Solution {
  public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bulls = 0;
        vector<int> cnt(10);
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
                secret[i] = ' ';
                guess[i] = ' ';
            } else {
                ++cnt[secret[i]-'0'];
            }
        }

        int cows = 0;
        for (int i = 0; i < n; ++i) {
            if (guess[i] == ' ')
                continue;
            if (cnt[guess[i]-'0'] > 0) {
                ++cows;
                --cnt[guess[i]-'0'];
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
