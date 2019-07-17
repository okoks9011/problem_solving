#include <iostream>
#include <string>

using namespace std;

const int kMod = 998244353;

unsigned long long Amplify(const string& s) {
    unsigned long long result = 0;
    for (auto& si : s) {
        result *= 100;
        result += (si-'0') * 11;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unsigned long long result = 0;
    for (int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;

        auto c = Amplify(tmp);
        c %= kMod;
        c *= n;
        result += c;
        result %= kMod;
    }
    cout << result << endl;
}
