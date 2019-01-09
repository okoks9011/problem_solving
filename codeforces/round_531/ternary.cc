#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::cin;

using std::map;

using std::string;

char NextChar(map<char, int>* cnt_ptr, int max_each) {
    auto& cnt = *cnt_ptr;

    for (auto& p : cnt) {
        if (p.second < max_each) {
            ++p.second;
            return p.first;
        }
    }

    return '9';
}

int main() {
    int n;
    cin >> n;

    const int max_each = n / 3;
    map<char, int> cnt{{'0', 0}, {'1', 0}, {'2', 0}};

    string s;
    cin >> s;

    for (auto& si : s)
        ++cnt[si];

    map<char, int> cnt0{{'0', 0}, {'1', 0}, {'2', 0}};
    cnt0['0'] = min(max_each, cnt['0']);
    cnt['0'] -= cnt0['0'];
    if (cnt['0'] && cnt['1'] < max_each) {
        cnt0['1'] = min(max_each-cnt['1'], cnt['0']);
        cnt['0'] -= cnt0['1'];
    }
    if (cnt['0']) {
        cnt0['2'] = min(max_each, cnt['0']);
        cnt['0'] -= cnt
    }
    for (auto& si : s) {
        if (si == '9')
            si = NextChar(&cnt, max_each);
    }
    cout << s << endl;
}
