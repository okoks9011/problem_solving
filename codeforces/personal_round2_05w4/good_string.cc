#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;


int CountSize(char a, char b, const string& s) {
    int size = 0;
    bool first = true;
    auto from = s.find(a);
    while (from != string::npos) {
        ++size;
        if (first)
            from = s.find(b, from);
        else
            from = s.find(a, from);
        first = !first;
    }
    if (size % 2)
        --size;
    return size;
}


void Solve() {
    string s;
    cin >> s;

    vector<int> cnt(10);
    for (auto& si : s)
        ++cnt[si-'0'];
    int max_size = *max_element(cnt.begin(), cnt.end());

    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (i == j)
                continue;
            max_size = max(max_size, CountSize(i+'0', j+'0', s));
        }
    }
    cout << s.size() - max_size << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
