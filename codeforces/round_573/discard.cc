#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    int m;
    cin >> m;

    long long k;
    cin >> k;

    vector<long long> p(m);
    for (auto& pi : p)
        cin >> pi;

    int result = 0;
    int i = 0;
    while (i < m) {
        long long np = p[i];
        np -= (i+1);
        np /= k;
        np += 1;
        np *= k;
        np += (i+1);

        while (i < m && p[i] < np)
            ++i;
        ++result;
    }
    cout << result << endl;
}
