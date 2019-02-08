#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    multiset<int> mset;
    for (int i = 0; i < n; ++i) {
        int di;
        cin >> di;
        mset.emplace(di);
    }

    int a = *mset.rbegin();
    for (int i = 1; i <= a; ++i) {
        if (a % i == 0) {
            mset.erase(mset.find(i));
        }
    }

    cout << a << " " << *mset.rbegin() << endl;
}
