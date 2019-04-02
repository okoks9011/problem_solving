#include <iostream>
#include <algorithm>

using namespace std;

int CalMaxProduct(int n) {
    if (n == 0)
        return 1;

    int d = n % 10;
    int result = CalMaxProduct(n / 10) * d;
    n -= d + 1;
    if (n >= 0)
        result = max(result, CalMaxProduct(n / 10) * 9);
    return result;
}

int main() {
    int n;
    cin >> n;

    cout << CalMaxProduct(n) << endl;
}
