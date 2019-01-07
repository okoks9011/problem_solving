#include <iostream>
#include <string>

using namespace std;

int main() {
    const string alpha = "abcdefghijklmnopqrstuvwxyz";

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;
        string chunk = alpha.substr(0, k);
        string result;
        for (int j = 0; j < n / k; ++j)
            result += chunk;
        result += alpha.substr(0, n % k);
        cout << result << endl;
    }
}
