#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;


enum Color {
    kWhite = 0,
    kGray = 1,
    kBlack = 2,
};


bool dfs(int cur, const vector<pair<int, int>>& arrow,
         vector<int>* visited_ptr, string* order_ptr) {
    auto& visited = *visited_ptr;
    if (visited[cur] == kBlack)
        return true;
    if (visited[cur] == kGray)
        return false;
    visited[cur] = kGray;

    for (auto& p : arrow) {
        if (p.first != cur)
            continue;
        if (!dfs(p.second, arrow, visited_ptr, order_ptr))
            return false;
    }
    visited[cur] = kBlack;

    auto& order = *order_ptr;
    order += cur + 'a';
    return true;
}


int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    for (auto& w : words)
        cin >> w;

    vector<pair<int, int>> arrow;
    for (int i = 0; i < n-1; ++i) {
        string& s = words[i];
        string& t = words[i+1];
        int j;
        for (j = 0; j < s.size() && j < t.size(); ++j) {
            if (s[j] == t[j])
                continue;
            arrow.emplace_back(s[j]-'a', t[j]-'a');
            break;
        }
        if (j == t.size() && s.size() > t.size()) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    string order;
    vector<int> visited(26);
    for (int i = 0; i < 26; ++i) {
        if (!dfs(i, arrow, &visited, &order)) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    reverse(order.begin(), order.end());
    cout << order << endl;
}
