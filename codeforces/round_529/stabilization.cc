#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

using std::max_element;
using std::min_element;
using std::min;

int main() {
    int n;
    cin >> n;

    vector<int> v1(n);
    for (int i = 0; i < n; ++i)
        cin >> v1[i];
    vector<int> v2(v1);

    auto max_it = max_element(v1.begin(), v1.end());
    int first_max = *max_it;
    v1.erase(max_it);
    int next_max = *max_element(v1.begin(), v1.end());

    auto min_it = min_element(v2.begin(), v2.end());
    int first_min = *min_it;
    v2.erase(min_it);
    int next_min = *min_element(v2.begin(), v2.end());

    cout << min(first_max-next_min, next_max-first_min) << endl;
}
