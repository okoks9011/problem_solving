#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> last(2);
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        last[tmp] = i;
    }

    cout << min(last[0], last[1]) + 1 << endl;
}
