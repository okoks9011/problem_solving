#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> s(n);
    for (auto& si : s) {
        char tmp;
        cin >> tmp;
        si = tmp - '0';
    }

    long long result = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] % 2 == 0)
            result += i+1;
    }
    cout << result << endl;
}
