#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<string> pattern{"RGB", "RBG", "BRG", "BGR", "GRB", "GBR"};
    vector<string> candi(pattern.size(), s);
    vector<int> costs(pattern.size());

    for (int i = 0; i < pattern.size(); ++i) {
        string& cur = candi[i];
        string& pi = pattern[i];
        for (int j = 0; j < cur.size(); ++j) {
            if (cur[j] != pi[j%3]) {
                cur[j] = pi[j%3];
                ++costs[i];
            }
        }
    }

    auto it = min_element(costs.begin(), costs.end());
    int min_idx = it - costs.begin();
    cout << *it << endl;
    cout << candi[min_idx] << endl;
}
