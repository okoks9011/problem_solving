#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> t(n);
    for (auto& ti : t)
        cin >> ti;

    int last_chunk = 0;
    int result = 0;
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j < n && t[i] == t[j])
               ++j;

        int cur_chunk = j - i;
        result = max(result, min(last_chunk, cur_chunk));
        last_chunk = cur_chunk;
        i = j - 1;
    }

    cout << result * 2 << endl;
}
