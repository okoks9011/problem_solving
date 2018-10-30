#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using std::cout;
using std::cin;
using std::endl;

using std::vector;

using std::stack;

using std::unordered_set;

int main() {
    int n;
    cin >> n;

    vector<int> a_vector;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        a_vector.emplace_back(a);
    }

    stack<int> s;
    for (auto it = a_vector.rbegin(); it != a_vector.rend(); ++it)
        s.push(*it);

    vector<int> b_vector;
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        b_vector.emplace_back(b);
    }

    unordered_set<int> backpack;
    for (const auto& bi : b_vector) {
        int c = 0;
        if (!backpack.count(bi)) {
            int last;
            do {
                last = s.top();
                s.pop();
                backpack.emplace(last);
                ++c;
            } while (last != bi);
        }
        cout << c << " ";
    }
    cout << endl;
}
