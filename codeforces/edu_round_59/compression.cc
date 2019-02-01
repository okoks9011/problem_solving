#include <iostream>
#include <deque>
#include <string>
#include <cctype>

using namespace std;

void Insert(deque<int>* row_ptr, char si) {
    char n = -1;
    if (isdigit(si))
        n = si - '0';
    else
        n = si - 'A' + 10;

    deque<int> tmp;
    for (int i = 0; i < 4; ++i) {
        tmp.emplace_front(n & 0x1);
        n >>= 1;
    }
    auto& row = *row_ptr;
    row.insert(row.end(), tmp.begin(), tmp.end());
}

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    deque<deque<int>> grid(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (auto& si : s)
            Insert(&grid[i], si);
    }

    int x = n;
    // Calulate GCD along the rows
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int k = j;
            while (k < n && grid[i][j] == grid[i][k])
                ++k;
            x = gcd(x, k-j);
            j = k-1;  // don't forget to -1
        }
    }

    // Calculate GCD along the columns
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            int k = i;
            while (k < n && grid[i][j] == grid[k][j])
                ++k;
            x = gcd(x, k-i);
            i = k-1; // don't forget to -1
        }
    }

    cout << x << endl;
}
