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

    vector<int> post{0, 0};
    for (int i = 0; i < n; ++i)
        post[i%2] += c[i];

    vector<int> pre{0, 0};
    int result = 0;
    for (int i = 0; i < n; ++i) {
        post[i%2] -= c[i];

        if (pre[0] + post[0] == pre[1] + post[1])
            ++result;

        pre[i%2==0] += c[i];
    }

    cout << result << endl;
}
