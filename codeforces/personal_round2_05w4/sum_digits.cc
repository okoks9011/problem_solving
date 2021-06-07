#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>


using namespace std;


void Solve() {
    string n;
    int s;
    cin >> n >> s;

    vector<int> digits(n.size());
    for (int i = 0; i < n.size(); ++i)
        digits[i] = n[i] - '0';
    reverse(digits.begin(), digits.end());

    vector<int> result{0};
    int i = 0;
    while (accumulate(digits.begin(), digits.end(), 0) > s) {
        if (digits[i] == 0) {
            ++i;
            result.emplace_back(0);
            continue;
        }
        if (i >= result.size())
            result.emplace_back(0);
        result[i] = 10 - digits[i];
        digits[i] = 10;
        for (int j = i; j < digits.size()-1; ++j) {
            if (digits[j] >= 10) {
                digits[j] -= 10;
                digits[j+1] += 1;
            } else {
                break;
            }
        }
        if (digits.back() >= 10) {
            digits.back() -= 10;
            digits.emplace_back(1);
        }
        ++i;
    }

    reverse(result.begin(), result.end());
    for (auto& ri : result)
        cout << ri;
    cout << endl;
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        Solve();
}
