#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>


using namespace std;


int CalMinCost(int start, int end, char c, const string& s) {
    assert(start < end);
    if (end-start == 1)
        return s[start] == c ? 0 : 1;

    int mid = start + (end-start)/2;
    int first_cost = 0;
    for (int i = start; i < mid; i++) {
        if (s[i] != c)
            first_cost++;
    }
    first_cost += CalMinCost(mid, end, c+1, s);

    int second_cost = 0;
    for (int i = mid; i < end; i++) {
        if (s[i] != c)
            second_cost++;
    }
    second_cost += CalMinCost(start, mid, c+1, s);

    return min(first_cost, second_cost);
}


void Solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    cout << CalMinCost(0, n, 'a', s) << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
        Solve();
}
