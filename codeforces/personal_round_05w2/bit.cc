// https://codeforces.com/problemset/problem/339/D
#include <iostream>
#include <vector>


using namespace std;


void Update(int pi, int bi, int total, vector<int>* h_ptr) {
    auto& h = *h_ptr;
    int t = total + pi;
    h[t] = bi;
    bool is_or = true;
    while (t > 1) {
        t /= 2;
        if (is_or)
            h[t] = h[2*t] | h[2*t+1];
        else
            h[t] = h[2*t] ^ h[2*t+1];
        is_or = !is_or;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int total = 1 << n;

    vector<int> h(total*2);
    for (int i = 0; i < total; ++i)
        cin >> h[total+i];

    bool is_or = true;
    for (int cur = total / 2; cur > 0; cur /= 2) {
        for (int i = cur; i < cur * 2; ++i) {
            if (is_or)
                h[i] = h[2*i] | h[2*i+1];
            else
                h[i] = h[2*i] ^ h[2*i+1];
        }
        is_or = !is_or;
    }

    for (int i = 0; i < m; ++i) {
        int pi, bi;
        cin >> pi >> bi;
        --pi;
        Update(pi, bi, total, &h);
        cout << h[1] << endl;
    }
}
