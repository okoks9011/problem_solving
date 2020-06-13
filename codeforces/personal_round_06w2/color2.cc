#include <iostream>
#include <vector>
#include <string>
#include <cassert>


using namespace std;


int main() {
    int v;
    cin >> v;

    vector<int> a(10);
    for (int i = 1; i <= 9; ++i)
        cin >> a[i];

    int min_v = 100001;
    int min_i = 0;
    for (int i = 1; i <= 9; ++i) {
        if (a[i] <= min_v) {
            min_v = a[i];
            min_i = i;
        }
    }
    assert(min_i != 0);

    string result(v / min_v, '0'+min_i);
    v %= min_v;
    for (int j = 0; j < result.size(); ++j) {
        for (int i = 9; i > min_i; --i) {
            if (v - (a[i] - min_v) < 0)
                continue;
            v -= (a[i] - min_v);
            result[j] = '0' + i;
            break;
        }
    }

    if (result.empty())
        cout << -1 << endl;
    else
        cout << result << endl;
}
