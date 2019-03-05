#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string ReverseQuad(stringstream* ss_ptr) {
    auto& ss = *ss_ptr;
    char head;
    ss >> head;
    if (head == 'w' || head == 'b')
        return {head};

    auto upper = ReverseQuad(ss_ptr);
    upper += ReverseQuad(ss_ptr);

    auto lower = ReverseQuad(ss_ptr);
    lower += ReverseQuad(ss_ptr);

    return "x" + lower + upper;
}

void Solve() {
    string s;
    cin >> s;

    stringstream ss(s);
    cout << ReverseQuad(&ss) << endl;;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
