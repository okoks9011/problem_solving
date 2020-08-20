#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


vector<int> CalFlip(string x) {
    x += '0';
    vector<int> result;
    for (int i = 0; i < x.size()-1; ++i) {
        if (x[i+1] != x[i])
            result.emplace_back(i);
    }
    return result;
}


void Solve() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    vector<int> result = CalFlip(a);
    vector<int> target = CalFlip(b);
    result.insert(result.end(), target.rbegin(), target.rend());

    cout << result.size() << " ";
    for (auto& ri : result)
        cout << ri+1 << " ";
    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
        Solve();
}
