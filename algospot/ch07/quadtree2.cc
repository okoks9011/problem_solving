#include <iostream>
#include <string>

using namespace std;

string ReverseQuad(string::iterator* it_ptr) {
    auto& it = *it_ptr;
    char head = *it;
    ++it;
    if (head == 'w' || head == 'b')
        return {head};

    auto upper = ReverseQuad(it_ptr);
    upper += ReverseQuad(it_ptr);

    auto lower = ReverseQuad(it_ptr);
    lower += ReverseQuad(it_ptr);

    return "x" + lower + upper;
}

void Solve() {
    string s;
    cin >> s;

    auto it = s.begin();
    cout << ReverseQuad(&it) << endl;;
}

int main() {
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i)
        Solve();
}
