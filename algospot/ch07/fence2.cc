#include <iostream>
#include <vector>

using namespace std;

void Solve() {
    int n;
    cin >> n;

    vector<int> h(n);
    for (auto& hi : h)
        cin >> hi;
    h.emplace_back(0);

    vector<int> stack;
    int result = 0;
    for (int i = 0; i < h.size(); ++i) {
        while (!stack.empty() && h[stack.back()] >= h[i]) {
            int j = stack.back();
            stack.pop_back();

            int width = i - 1 - (stack.empty() ? -1 : stack.back());
            result = max(result, width*h[j]);
        }
        stack.emplace_back(i);
    }
    cout << result << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
