#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
    int n;
    cin >> n;

    if (n % 4 == 1 || n % 4 == 2)
        cout << "1" << endl;
    else
        cout << "0" << endl;
}
