#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int result = 0;
    for (int i = 1; i <= n; ++i) {
        int ai;
        cin >> ai;
        int e = 2 * (i - 1);
        result += 2 * e * ai;
    }

    cout << result << endl;
}
