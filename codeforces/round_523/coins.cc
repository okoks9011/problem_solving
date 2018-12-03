#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;

using std::vector;

int main() {
    int n, s;
    cin >> n >> s;

    int coins = 0;
    coins = s / n;
    if (s % n)
        ++coins;

    cout << coins << endl;
}
