#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <cassert>


using namespace std;


int main() {
    int n;
    cin >> n;

    vector<pair<string, int>> scores(n);
    unordered_map<string, int> sum;
    for (auto& score : scores) {
        cin >> score.first >> score.second;
        sum[score.first] += score.second;
    }

    int max_v = 0;
    for (auto& p : sum)
        max_v = max(max_v, p.second);

    unordered_map<string, int> candi;
    for (auto& p : sum) {
        if (p.second == max_v)
            candi[p.first] = 0;
    }

    assert(candi.size() > 0);
    if (candi.size() == 1) {
        auto p = *candi.begin();
        cout << p.first << endl;
        return 0;
    }

    for (auto& score : scores) {
        auto it = candi.find(score.first);
        if (it == candi.end())
            continue;
        it->second += score.second;
        if (it->second >= max_v) {
            cout << it->first << endl;
            return 0;
        }
    }
    assert(false);
}
