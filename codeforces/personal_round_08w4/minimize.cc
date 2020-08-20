#include <iostream>
#include <vector>
#include <string>


using namespace  std;


void Solve() {
    string a;
    cin >> a;

    vector<char> even;
    vector<char> odd;
    for (auto& ai : a) {
        int d = ai - '0';
        if (d % 2)
            odd.emplace_back(ai);
        else
            even.emplace_back(ai);
    }

    string result;
    int odd_idx = 0;
    int even_idx = 0;
    while (odd_idx < odd.size() && even_idx < even.size()) {
        if (odd[odd_idx] < even[even_idx]) {
            result += odd[odd_idx];
            ++odd_idx;
        } else {
            result += even[even_idx];
            ++even_idx;
        }
    }
    while (odd_idx < odd.size()) {
        result += odd[odd_idx];
        ++odd_idx;
    }
    while (even_idx < even.size()) {
        result += even[even_idx];
        ++even_idx;
    }

    cout << result << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
