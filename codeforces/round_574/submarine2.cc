#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int kMod = 998244353;

unsigned long long Amplify(const string& s, int n) {
    int close = s.size() - n;
    unsigned long long result = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i < close)
            result *= 10;
        else
            result *= 100;
        result += s[i] - '0';
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> cnt(11);
    vector<string> nums(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ++cnt[s.size()];
        nums[i] = s;
    }

    unsigned long long result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < 10; ++j) {
            if (cnt[j] == 0)
                continue;
            auto c = Amplify(nums[i], j);
            c %= kMod;
            c *= cnt[j];
            result += c;
            result %= kMod;

            c = Amplify(nums[i], j-1) * 10;
            c %= kMod;
            c *= cnt[j];
            result += c;
            result %= kMod;
        }
    }
    cout << result << endl;
}
