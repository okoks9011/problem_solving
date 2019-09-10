#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int b, g, n;
    cin >> b >> g >> n;

    int left = n - min(n, b);
    int right = min(n, g);

    cout << right-left+1 << endl;
}
