#include <iostream>
#include <string>
#include <utility>


using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    string result(k, 0);
    for (int i = 0; i < k; i++)
        result[i] = s[i%n];

    while (s.size() >= 1) {
        string cur(k, 0);
        for (int i = 0; i < k; i++)
            cur[i] = s[i%s.size()];
        if (cur < result)
            swap(cur, result);
        s.pop_back();
    }
    cout << result << endl;
}
