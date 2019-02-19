#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> candi;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        candi.emplace(ai);
        sum += ai;
    }

    int aj = *candi.begin();
    int result = sum;
    for (auto& ai : candi) {
        for (int x = 1; x <= ai; ++x) {
            if (ai % x)
                continue;
            int new_sum = sum - ai - aj + (ai / x) + (aj * x);
            result = min(result, new_sum);
        }
    }

    cout << result << endl;
}
