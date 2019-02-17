#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, v;
    cin >> n >> v;

    int remain = n - 1;
    int cost = min(remain, v);

    remain -= min(remain, v);
    int j = 2;
    for (int i = 0; i < remain; ++i) {
        cost += j;
        ++j;
    }

    cout << cost << endl;
}
