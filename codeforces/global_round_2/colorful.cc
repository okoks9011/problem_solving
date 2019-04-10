#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (auto& ci : c)
        cin >> ci;

    int left = 0;
    while (c[left] == c.back())
        ++left;

    int right = n - 1;
    while (c[right] == c.front())
        --right;

    cout << max(n-1-left, right) << endl;
}
