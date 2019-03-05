#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> result(a.size()+b.size()-1);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            result[i+j] += a[i] * b[j];
        }
    }
    return result;
}

vector<int> Convert(const string& t) {
    vector<int> result(t.size());
    for (int i = 0; i < t.size(); ++i) {
        if (t[i] == 'M')
            result[i] = 1;
        else
            result[i] = 0;
    }
    return result;
}

template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
    for (auto& vi : v)
        cout << vi << " ";
    return os;
}

void Solve() {
    string m_str;
    cin >> m_str;

    string f_str;
    cin >> f_str;

    auto m = Convert(m_str);
    auto f = Convert(f_str);

    reverse(m.begin(), m.end());
    auto mult = Multiply(m, f);
    int margin = m.size() - 1;
    cout << count(mult.begin()+margin, mult.end()-margin, 0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
