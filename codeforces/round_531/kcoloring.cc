#include <iostream>
#include <vector>
#include <unordered_set>

using std::cout;
using std::endl;
using std::cin;

using std::vector;

using std::unordered_set;

bool PutI(int ai, vector<unordered_set<int>>* colors_ptr, vector<int>* result_ptr) {
    auto& colors = *colors_ptr;
    auto& result = *result_ptr;

    for (int i = 0; i < colors.size(); ++i) {
        if (!colors[i].count(ai)) {
            colors[i].emplace(ai);
            result.emplace_back(i+1);
            return true;
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<unordered_set<int>> colors(k);
    vector<int> result;

    int i = 0;
    for (; i < k; ++i) {
        int ai;
        cin >> ai;
        colors[i].emplace(ai);
        result.emplace_back(i+1);
    }

    for (; i < n; ++i) {
        int ai;
        cin >> ai;
        if (!PutI(ai, &colors, &result)) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for (auto& ci : result)
        cout << ci << " ";
    cout << endl;
}
