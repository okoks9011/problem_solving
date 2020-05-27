#include <iostream>
#include <vector>


using namespace std;


int main() {
    long long n;
    cin >> n;

    vector<int> small{0, 1, 2, 6, 12};
    if (n < small.size()) {
        cout << small[n] << endl;
        return 0;
    }

    if (n % 2) {
        cout <<  (n-2) * (n-1) * n << endl;
    } else {
        if (n % 3 == 0)
            cout << (n-3) * (n-2) * (n-1) << endl;
        else
            cout << (n-3) * (n-1) * n << endl;
    }
}
