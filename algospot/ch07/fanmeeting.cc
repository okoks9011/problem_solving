#include <iostream>
#include <vector>
#include <algorithm>

#include <random>
#include <chrono>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto& vi : v)
        cout << vi << " ";
    return os;
}

vector<int> Multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> result(a.size()+b.size()-1);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            result[i+j] += a[i] * b[j];
        }
    }
    return result;
}

void AddShift(vector<int>* to_ptr, const vector<int>& from, int shift) {
    auto& to = *to_ptr;
    int total_size = from.size() + shift;
    if (to.size() < total_size)
        to.resize(total_size);

    for (int i = 0; i < from.size(); ++i)
        to[i+shift] += from[i];
}

void Sub(vector<int>* to_ptr, const vector<int>& from) {
    auto& to = *to_ptr;
    for (int i = 0; i < from.size(); ++i)
        to[i] -= from[i];
}

vector<int> Karatsuba(const vector<int>& a, const vector<int>& b) {
    const int limit = 50;
    if (a.size() <= limit || b.size() <= limit)
        return Multiply(a, b);

    if (b.size() > a.size())
        return Karatsuba(b, a);

    int half = a.size() / 2;
    vector<int> a0(a.begin(), a.begin()+half);
    vector<int> a1(a.begin()+half, a.end());

    if (b.size() < half) {
        auto a0b = Karatsuba(a0, b);
        auto a1b = Karatsuba(a1, b);
        AddShift(&a0b, a1b, half);

        return a0b;
    }

    vector<int> b0(b.begin(), b.begin()+half);
    vector<int> b1(b.begin()+half, b.end());

    auto a0b0 = Karatsuba(a0, b0);
    auto a1b1 = Karatsuba(a1, b1);

    AddShift(&a0, a1, 0);
    AddShift(&b0, b1, 0);
    auto midterm = Karatsuba(a0, b0);
    Sub(&midterm, a0b0);
    Sub(&midterm, a1b1);

    AddShift(&a0b0, a1b1, 2*half);
    AddShift(&a0b0, midterm, half);
    while (a0b0.size() > 1 && a0b0.back() == 0)
        a0b0.pop_back();

    return a0b0;
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

void Solve() {
    string m_str;
    cin >> m_str;

    string f_str;
    cin >> f_str;

    auto m = Convert(m_str);
    auto f = Convert(f_str);

    reverse(m.begin(), m.end());
    auto mult = Karatsuba(f, m);
    int margin = m.size() - 1;
    cout << count(mult.begin()+margin, mult.end()-margin, 0) << endl;
}

vector<int> GenSample() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1000);;

    vector<int> result(dis(gen));
    for (auto& ri : result)
        ri = dis(gen) % 2;
    return result;
}

void Test() {
    auto v1 = GenSample();
    auto v2 = GenSample();

    auto k = Karatsuba(v1, v2);
    auto m = Multiply(v1, v2);
    if (k == m) {
        cout << "Karatsuba and Multiply are same" << endl;
    } else {
        cout << "Karatsuba and Multiply are differ" << endl;
        cout << "v1: " << v1 << endl;
        cout << "v2: " << v2 << endl;
        cout << "k: " << k << endl;
        cout << "m: " << m << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < c; ++i)
        Solve();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Total time: " << duration.count() / 1000.0 << " s" << endl;
}
