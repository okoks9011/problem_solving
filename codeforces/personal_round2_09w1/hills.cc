#include <iostream>
#include <vector>


using namespace std;


bool IsPoint(int a, int b, int c) {
    return (a < b && b > c) || (a > b && b < c);
}


void Solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a)
        cin >> ai;

    vector<char> point(n);
    int intimidation = 0;
    for (int i = 1; i < n-1; i++) {
        if (IsPoint(a[i-1], a[i], a[i+1])) {
            point[i] = true;
            intimidation++;
        }
    }

    int result = intimidation;
    for (int i = 1; i < n-1; i++) {
        int ai = a[i-1];
        int cur = intimidation;
        if (point[i-1])
            cur--;
        if (point[i])
            cur--;
        // point[n-1] == false, so it won't access a[n].
        if (point[i+1] && !IsPoint(ai, a[i+1], a[i+2]))
            cur--;
        if (!point[i+1] && i < n-2 && IsPoint(ai, a[i+1], a[i+2]))
            cur++;
        result = min(result, cur);

        ai = a[i+1];
        cur = intimidation;
        if (point[i+1])
            cur--;
        if (point[i])
            cur--;
        // point[0] == fales, so it won't access a[-1].
        if (point[i-1] && !IsPoint(a[i-2], a[i-1], ai))
            cur--;
        if (!point[i-1] && i > 1 && IsPoint(a[i-2], a[i-1], ai))
            cur++;
        result = min(result, cur);
    }

    cout << result << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
        Solve();
}
