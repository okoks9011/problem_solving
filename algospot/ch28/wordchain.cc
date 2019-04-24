#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

const int kAlpha = 26;

void GenEulerianCircuit(int u, vector<vector<int>>* adj_ptr,
                        vector<int>* circuit_ptr) {
    auto& adj = *adj_ptr;
    for (int i = 0; i < kAlpha; ++i) {
        while (adj[u][i]) {
            --adj[u][i];
            GenEulerianCircuit(i, adj_ptr, circuit_ptr);
        }
    }
    auto& circuit = *circuit_ptr;
    circuit.emplace_back(u);
}

void Solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(kAlpha, vector<int>(kAlpha));
    map<pair<int, int>, vector<string>> words;
    int words_cnt = 0;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        int f = word.front() - 'a';
        int t = word.back() - 'a';
        ++adj[f][t];
        words[{f, t}].emplace_back(word);
        ++words_cnt;
    }

    int start = -1;
    int end = -1;
    for (int i = 0; i < kAlpha; ++i) {
        int out_cnt = 0;
        int in_cnt = 0;
        for (int j = 0; j < kAlpha; ++j) {
            out_cnt += adj[i][j];
            in_cnt += adj[j][i];
        }
        if (out_cnt == in_cnt)
            continue;

        if (start == -1 && out_cnt-in_cnt == 1) {
            start = i;
        } else if (end == -1 && in_cnt-out_cnt == 1) {
            end = i;
        } else {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    if ((start != -1 && end == -1) ||
        (start == -1 && end != -1)) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    if (start == -1) {
        auto& p = words.begin()->first;
        start = p.first;
    }

    vector<int> circuit;
    GenEulerianCircuit(start, &adj, &circuit);
    if (circuit.size()-1 != words_cnt) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for (int i = circuit.size()-1; i >= 1; --i) {
        auto& candi = words[{circuit[i], circuit[i-1]}];
        cout << candi.back() << " ";
        candi.pop_back();
    }
    cout << endl;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
