#include <deque>
#include <iostream>


using namespace std;


void Solve() {
    int n;
    cin >> n;

    if (n <= 3) {
        cout << -1 << endl;
        return;
    }

    int left = 1;
    int right = n;
    deque<int> result;
    if (n % 2)
        result.emplace_back(n/2+1);
    for (int i = 0; i < n/2; ++i) {
        if (i % 2 == 0) {
            result.emplace_front(left++);
            result.emplace_back(right--);
        } else {
            result.emplace_back(left++);
            result.emplace_front(right--);
        }
    }

    for (auto& ri : result)
        cout << ri << " ";
    cout << endl;
}


int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
