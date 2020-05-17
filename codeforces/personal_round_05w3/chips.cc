#include <iostream>
#include <string>


using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    string result;
    result += string(n-1, 'U');
    result += string(m-1, 'L');

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0)
            result += string(m-1, 'R');
        else
            result += string(m-1, 'L');
        if (i != n-1)
            result += 'D';
    }

    cout << result.size() << endl;
    cout << result << endl;
}
