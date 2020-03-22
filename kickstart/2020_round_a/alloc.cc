#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


void Solve(int t) {
    int n, b;
    cin >> n >> b;

    vector<int> houses(n);
    for (auto& h : houses)
        cin >> h;

    sort(houses.begin(), houses.end());
    int sum = 0;
    int cnt = 0;
    for (auto& h : houses) {
        sum += h;
        if (sum > b)
            break;
        ++cnt;
    }

    cout << "Case #" << t << ": " << cnt << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        Solve(i+1);
}
