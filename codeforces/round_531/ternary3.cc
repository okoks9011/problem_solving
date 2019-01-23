#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int CalNeed(const vector<int>& cnt, const vector<int>& goal) {
    int total = 0;
    for(int i = 0; i < cnt.size(); ++i) {
        total += abs(cnt[i] - goal[i]);
    }

    return total / 2;
}

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> cnt(3);
    for (int i = 0; i < 3; ++i)
        cnt[i] = count(s.begin(), s.end(), '0'+i);
    vector<int> goal(3, n / 3);

    int remain = CalNeed(cnt, goal);
    int i = 0;
    while (remain) {
        int si = s[i] - '0';
        --cnt[si];
        for (int j = 0; j < 3; ++j) {
            if (goal[j] <= 0)
                continue;

            --goal[j];
            if (si == j)
                break;
            if (CalNeed(cnt, goal) < remain) {
                s[i] = j + '0';
                --remain;
                break;
            }
            ++goal[j];
        }
        ++i;
    }
    cout << s << endl;
}
