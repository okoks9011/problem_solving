#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    vector<int> sum(200001);
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j)
            ++sum[a[i]+a[j]];
    }

    cout << *max_element(sum.begin(), sum.end()) << endl;
}
