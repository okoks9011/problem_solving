#include <iostream>
#include <vector>

using namespace std;

bool genSeq(const vector<vector<int>>& a, int cur, int next, vector<int>* result_ptr) {
    auto& result = *result_ptr;
    result.clear();

    for (int i = 0; i < a.size()-1; ++i) {
        int nnext = -1;
        if (a[cur][0] == next) {
            nnext = a[cur][1];
        } else if (a[cur][1] == next) {
            nnext = a[cur][0];
        } else {  // cur's next not exist in a
            return false;
        }
        cur = next;
        next = nnext;
        result.emplace_back(nnext);
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n+1, vector<int>(2));
    for (int i = 1; i <= n; ++i) {
        cin >> a[i][0] >> a[i][1];
    }

    vector<int> result;
    if (!genSeq(a, 1, a[1][0], &result))
        genSeq(a, 1, a[1][1], &result);

    for (auto& ri : result)
        cout << ri << " ";
    cout << endl;
}
