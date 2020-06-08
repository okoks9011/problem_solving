#include <iostream>
#include <vector>
#include <limits>


using namespace std;


int main() {
    int v;
    cin >> v;

    int min_price = numeric_limits<int>::max();
    int min_d = -1;
    for (int i = 1; i <= 9; ++i) {
        int cur_price;
        cin >> cur_price;
        if (cur_price <= min_price) {
            min_d = i;
            min_price = cur_price;
        }
    }

    if (min_price > v) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < v / min_price; ++i)
        cout << min_d;
    cout << endl;
}
