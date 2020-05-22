#include <iostream>
#include <string>
#include <algorithm>


using namespace std;


string Encode(int x) {
    string result;
    while (x) {
        --x;
        result += (x % 26) + 'A';
        x /= 26;
    }
    reverse(result.begin(), result.end());
    return result;
}


int Decode(string x) {
    int result = 0;
    for (auto& c : x) {
        result *= 26;
        result += c - 'A' + 1;
    }
    return result;
}


void Solve() {
    string s;
    cin >> s;

    auto dit = find_if(s.begin(), s.end(), [](char& c){ return '0' <= c && c <= '9'; });
    auto cit = find(dit, s.end(), 'C');
    if (cit != s.end()) {
        int row = stoi(string(s.begin()+1, cit));
        ++cit;
        int col = stoi(string(cit, s.end()));
        string encoded = Encode(col);
        cout << encoded << row << endl;
    } else {
        int decoded = Decode(string(s.begin(), dit));
        cout << "R" << string(dit, s.end()) << "C" << decoded << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        Solve();
}
