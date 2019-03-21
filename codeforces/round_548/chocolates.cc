#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    long long result = 0;
    int cur = a.back();
    for (int i = n-1; i >= 0; --i) {
        if (cur == 0)
            break;
        cur = min(cur, a[i]);
        result += cur;
        --cur;
    }

    cout << result << endl;
}
