#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;

using std::vector;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int result = 0;
    for (int i = 2; i < n; ++i) {
        if (v[i-2] && v[i-1] == 0 && v[i]) {
            v[i] = 0;
            ++result;
        }
    }
    cout << result << endl;
}
