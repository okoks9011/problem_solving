#include <string>
#include <iostream>
#include <cassert>
#include <vector>


using namespace std;


bool CheckEquivalent(int start_a, int end_a,
                     int start_b, int end_b,
                     const string& a, const string& b) {
    assert(start_a <= end_a);
    assert(start_b <= end_b);

    if (end_a - start_a != end_b - start_b)
        return false;
    int length = end_a - start_a + 1;
    bool equal = true;
    for (int i = 0; i < length; ++i) {
        if (a[start_a+i] != b[start_b+i])
            equal = false;
    }
    if (equal)
        return true;
    if (length % 2)
        return false;

    vector<int> cnt_a(26);
    vector<int> cnt_b(26);
    for (int i = 0; i < length; ++i) {
        ++cnt_a[a[start_a+i]-'a'];
        ++cnt_b[b[start_b+i]-'a'];
    }
    if (cnt_a != cnt_b)
        return false;

    int mid_a = (start_a + end_a) / 2;
    int mid_b = (start_b + end_b) / 2;
    if (CheckEquivalent(start_a, mid_a, start_b, mid_b, a, b) &&
        CheckEquivalent(mid_a+1, end_a, mid_b+1, end_b, a, b))
        return true;
    return (CheckEquivalent(start_a, mid_a, mid_b+1, end_b, a, b) &&
            CheckEquivalent(mid_a+1, end_a, start_b, mid_b, a, b));
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    if (CheckEquivalent(0, a.size()-1, 0, b.size()-1, a, b))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
