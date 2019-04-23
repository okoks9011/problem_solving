#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int effect = n - 10;
    int cnt = 0;
    for (int i = 0; i < effect; ++i) {
        char si;
        cin >> si;
        if (si == '8')
            ++cnt;
    }

    if (cnt > effect/2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
