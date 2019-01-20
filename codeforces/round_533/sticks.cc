#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>

using namespace std;

int CalCost(vector<int>& a, int t) {
    int cost = 0;
    for (auto& ai : a) {
        if (abs(ai - t) <= 1)
            continue;
        else if (ai > t)
            cost += (ai - t - 1);
        else
            cost += (t - ai - 1);
    }
    return cost;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int min_cost = numeric_limits<int>::max();
    int min_t = 0;
    for (int i = 1; i <= 1000; ++i) {
        int cur_cost = CalCost(a, i);
        if (cur_cost < min_cost) {
            min_cost = cur_cost;
            min_t = i;
        }
    }

    cout << min_t << " " << min_cost << endl;
}
