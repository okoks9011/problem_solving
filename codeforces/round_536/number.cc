#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    sort(a.begin(), a.end());
    long long sum = 0;
    while (!a.empty()) {
        int s = a.front() + a.back();
        sum += s * s;
        a.pop_front();
        a.pop_back();
    }
    cout << sum << endl;
}
